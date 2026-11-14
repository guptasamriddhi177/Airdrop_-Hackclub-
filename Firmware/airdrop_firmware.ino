// AirDrop Rev-A firmware starter
// Arduino framework / ESP32-WROOM-32E
// Hardware pin map matches docs/wiring_diagram.md and pcb/AirDrop.kicad_pcb
#include <Arduino.h>
#include <Wire.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include <Adafruit_BME680.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>

#define SDA_PIN 21
#define SCL_PIN 22
#define AIRFLOW_ADC 34
#define WIND_PULSE 35
#define LEAK_1 32
#define LEAK_2 33
#define LEAK_3 27
#define US1_TRIG 25
#define US1_ECHO 26
#define US2_TRIG 14
#define US2_ECHO 13

const char* WIFI_SSID = "YOUR_WIFI_SSID";
const char* WIFI_PASSWORD = "YOUR_WIFI_PASSWORD";
const char* FIREBASE_URL = "https://YOUR_PROJECT-default-rtdb.asia-southeast1.firebasedatabase.app/airdrop/AIRDROP_001.json";

Adafruit_BME680 bme;
Adafruit_MPU6050 mpu;
volatile uint32_t windPulses = 0;
uint32_t lastUpload = 0;

void IRAM_ATTR onWindPulse(){ windPulses++; }
float readDistance(uint8_t trig, uint8_t echo){
  digitalWrite(trig, LOW); delayMicroseconds(3);
  digitalWrite(trig, HIGH); delayMicroseconds(10); digitalWrite(trig, LOW);
  uint32_t us = pulseIn(echo, HIGH, 30000);
  return us ? (us * 0.0343f / 2.0f) : NAN;
}
int riskScore(float t, float h, float p, float gas, int airflow, uint32_t wind,
               float ax, float ay, float az, bool leak1, bool leak2, bool leak3,
               float d1, float d2){
  int s=0;
  if (isnan(t)||isnan(h)||isnan(p)||isnan(gas)) s+=15;
  if (t>40 || t<0) s+=12;
  if (h>85) s+=10;
  if (p<950 || p>1050) s+=8;
  if (gas<8000) s+=12;
  if (airflow<100 || airflow>3900) s+=8;
  if (wind>80) s+=8;
  float amag=sqrtf(ax*ax+ay*ay+az*az);
  if (fabsf(amag-9.81f)>3.0f) s+=12;
  if (leak1) s+=12; if (leak2) s+=12; if (leak3) s+=12;
  if (!isnan(d1) && d1<15) s+=8;
  if (!isnan(d2) && d2<15) s+=8;
  return constrain(s,0,100);
}
void setup(){
  Serial.begin(115200); Wire.begin(SDA_PIN,SCL_PIN);
  pinMode(LEAK_1,INPUT_PULLUP); pinMode(LEAK_2,INPUT_PULLUP); pinMode(LEAK_3,INPUT_PULLUP);
  pinMode(US1_TRIG,OUTPUT); pinMode(US1_ECHO,INPUT); pinMode(US2_TRIG,OUTPUT); pinMode(US2_ECHO,INPUT);
  pinMode(WIND_PULSE,INPUT_PULLUP); attachInterrupt(digitalPinToInterrupt(WIND_PULSE),onWindPulse,RISING);
  if(!bme.begin(0x76)){ Serial.println("BME680 not found"); }
  if(!mpu.begin()){ Serial.println("MPU6050 not found"); }
  WiFi.begin(WIFI_SSID,WIFI_PASSWORD);
}
void loop(){
  if(bme.performReading()){
    sensors_event_t a,g,temp; mpu.getEvent(&a,&g,&temp);
    bool leak = !digitalRead(LEAK_1)||!digitalRead(LEAK_2)||!digitalRead(LEAK_3);
    float d1=readDistance(US1_TRIG,US1_ECHO), d2=readDistance(US2_TRIG,US2_ECHO);
    uint32_t pulses=windPulses; windPulses=0;
    int airflow=analogRead(AIRFLOW_ADC);
    int score=riskScore(bme.temperature,bme.humidity,bme.pressure/100.0f,bme.gas_resistance,airflow,pulses,a.acceleration.x,a.acceleration.y,a.acceleration.z,!digitalRead(LEAK_1),!digitalRead(LEAK_2),!digitalRead(LEAK_3),d1,d2);
    Serial.printf("T=%.2f H=%.2f P=%.2f gas=%.0f airflow=%d wind=%lu d1=%.1f d2=%.1f risk=%d\n",bme.temperature,bme.humidity,bme.pressure/100.0f,bme.gas_resistance,airflow,pulses,d1,d2,score);
    if(WiFi.status()==WL_CONNECTED && millis()-lastUpload>5000){
      HTTPClient http; http.begin(FIREBASE_URL); http.addHeader("Content-Type","application/json");
      String payload=String("{\"environment\":{\"temperature\":")+bme.temperature+",\"humidity\":"+bme.humidity+",\"pressure\":"+(bme.pressure/100.0f)+",\"gas_resistance\":"+bme.gas_resistance+"},\"airflow\":{\"adc\":"+airflow+",\"wind_pulses\":"+pulses+"},\"movement\":{\"ax\":"+a.acceleration.x+",\"ay\":"+a.acceleration.y+",\"az\":"+a.acceleration.z+"},\"leak_zones\":{\"zone_1\":"+(!digitalRead(LEAK_1))+",\"zone_2\":"+(!digitalRead(LEAK_2))+",\"zone_3\":"+(!digitalRead(LEAK_3))+"},\"distance\":{\"sensor_1\":"+d1+",\"sensor_2\":"+d2+"},\"risk\":{\"score\":"+score+"},\"timestamp\":"+millis()+"}");
      http.PUT(payload); http.end(); lastUpload=millis();
    }
  }
  delay(1000);
}
