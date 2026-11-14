
AIRDROP

Smart Environmental Safety & Early Warning System
<p align="center">
<img width="720" height="405" alt="608bbcf5-2657-4c95-96f3-e0eb5eb77617_thumb" src="https://github.com/user-attachments/assets/1a9264c4-4460-435c-a14a-df0e66fcc263" />

</p><p align="center">
  DETECT. PREDICT. ALERT. PROTECT.
</p><p align="center">
  An intelligent environmental monitoring ecosystem combining IoT, embedded systems, cloud connectivity, and wearable technology.
</p>---

Overview

AIRDROP is a Smart Environmental Safety and Early Warning System designed to monitor environmental conditions, identify potentially unsafe situations, and deliver timely alerts.

Unlike conventional single-purpose detectors, AIRDROP combines multiple sensors, dual ESP32 controllers, cloud-based data synchronization, a digital monitoring dashboard, and a connected wearable.

The project consists of two primary hardware components:

- AIRDROP Pod: A stationary multi-sensor environmental monitoring unit.
- AIRDROP Wearable: A connected wearable designed to receive alerts, display risk information, and provide an SOS interface.

The ultimate objective is to create an integrated environmental safety ecosystem that makes important safety information more accessible.

Project Gallery

1. AIRDROP Sensor Pod & Wearable
<img width="719" height="469" alt="ca7ac56a-df83-47e9-8123-74f384368aa6_thumb" src="https://github.com/user-attachments/assets/be77375b-b225-491a-b1bb-dcb774df72bc" />

<p align="center">
  
2. Schematics
<img width="720" height="393" alt="a742cac5-bd06-4268-bb08-509a6f3966fe_thumb" src="https://github.com/user-attachments/assets/b206cf2a-07fa-484e-95f8-54b8cb96b942" />

<p align="center">
  
3. 3D mechanical assembly 
<img width="720" height="960" alt="1aeadbcd-61e0-4052-9afa-a80fb1f66d85_thumb" src="https://github.com/user-attachments/assets/f932976d-cbe9-497c-8af8-18848c3b8b51" />

<p align="center">
  
4. PCB design 
<img width="720" height="960" alt="202314ac-1ba9-45b3-9563-10a41cd0129d_thumb" src="https://github.com/user-attachments/assets/f03df1f1-3559-4c5c-88ad-842a7933f0be" />

<p align="center">
  
5. AIRDROP Wearable
6. 
 <img width="720" height="480" alt="142408ac-85ca-4ca9-91b3-9c55f218950b_thumb" src="https://github.com/user-attachments/assets/39ad8f4b-91e3-46b9-9273-36a730d153d3" />

<p align="center">
  
6. Digital Monitoring Dashboard

<img width="720" height="480" alt="0767eb2a-9c46-4a95-b973-f2ec27415a5e_thumb" src="https://github.com/user-attachments/assets/8c68d075-eee7-4279-bb78-c9831203a91e" />


---

Key Features

- Multi-sensor environmental monitoring.
- Temperature and humidity monitoring.
- Air-quality monitoring.
- Airflow detection.
- Water leakage detection.
- Motion and orientation sensing.
- Distance and proximity monitoring.
- Dual ESP32 architecture.
- Wireless data communication.
- Firebase Realtime Database integration.
- Real-time digital monitoring.
- Environmental risk classification.
- Wearable alert notifications.
- Emergency SOS interface.
- Location-aware monitoring architecture.
- Future AI-assisted environmental risk analysis.

System Architecture

AIRDROP follows a hardware-to-cloud architecture in which environmental data is collected, processed, transmitted, and presented through a connected digital interface.

       ENVIRONMENTAL CONDITIONS
                  |
                  v
          AIRDROP SENSOR POD
                  |
          MULTIPLE SENSORS
                  |
          +-------+-------+
          |               |
          v               v
       ESP32 NODE 1    ESP32 NODE 2
          |               |
          +-------+-------+
                  |
          WIRELESS DATA
                  |
                  v
          FIREBASE RTDB
                  |
          +-------+-------+
          |               |
          v               v
     DIGITAL DASHBOARD  RISK ENGINE
          |               |
          +-------+-------+
                  |
                  v
          AIRDROP WEARABLE
                  |
           ALERTS / SOS

Hardware Components

Component| Function
ESP32-WROOM-32 × 2| Processing and connectivity
BME680| Environmental and air-quality sensing
MPU6050| Motion and orientation sensing
HC-SR04| Distance measurement
Airflow Sensor| Air movement monitoring
Water Leak Sensor| Leakage detection
Wearable Display| Alert visualization
Power System| Device power management

Controller Distribution

Node 1

- ESP32-WROOM-32
- BME680
- HC-SR04

Node 2

- ESP32-WROOM-32
- MPU6050
- HC-SR04

Airflow and water-leak sensors are included in the broader monitoring architecture.

PCB & Electronics Design

AIRDROP uses a custom PCB architecture designed in KiCad.

Specification| Design
Main Controller| ESP32-WROOM-32
Controller Configuration| Dual ESP32
PCB Type| Custom combined PCB
PCB Dimensions| 50 × 50 mm
PCB Layers| 4
Power Architecture| USB-powered
PCB Design Software| KiCad

The objective is to consolidate the electronics into a compact integrated design.

AIRDROP Wearable

The AIRDROP wearable extends environmental monitoring beyond the stationary pod.

Its intended capabilities include:

- Wireless safety notifications.
- Risk-level visualization.
- Environmental alert information.
- Emergency SOS interaction.
- Connectivity with the AIRDROP ecosystem.

The wearable is designed to make important safety information accessible without requiring constant access to the main dashboard.

Software Architecture

AIRDROP integrates embedded firmware, wireless communication, cloud infrastructure, and a digital application.

Layer| Technology
Embedded Hardware| ESP32
Firmware| Arduino / Embedded C++
PCB Design| KiCad
Communication| Wi-Fi / Bluetooth
Cloud Database| Firebase Realtime Database
Database Region| asia-southeast1
Dashboard| Digital monitoring interface
Risk Assessment| Multi-sensor risk engine

Risk Classification

AIRDROP uses a proposed 0–100 risk classification model.

Score| Classification| Indicator
0–25| Safe| 🟢
26–50| Caution| 🟡
51–75| Warning| 🟠
76–100| Critical| 🔴

The proposed scoring system combines multiple environmental indicators to categorize reported conditions.

These are prototype design categories, not certified safety thresholds. Calibration and field validation are required.

How AIRDROP Works

1. Environmental Monitoring: Sensors collect environmental readings.
2. Data Acquisition: ESP32 controllers receive sensor information.
3. Processing: The embedded system processes the collected readings.
4. Wireless Communication: Relevant information is transmitted.
5. Cloud Synchronization: Firebase stores and synchronizes monitoring data.
6. Risk Assessment: The software evaluates available environmental indicators.
7. Visualization: The dashboard presents readings and risk classifications.
8. Wearable Alerts: The wearable is designed to receive important notifications.

Technology Stack

- ESP32-WROOM-32
- BME680
- MPU6050
- HC-SR04
- Airflow Sensor
- Water Leak Sensor
- Arduino Framework
- Embedded C/C++
- KiCad
- Firebase Realtime Database
- Wi-Fi
- Bluetooth
- 3D CAD

Repository Structure

AIRDROP/
│
├── README.md
│
├── Images/
│   ├── airdrop-banner.png
│   ├── hardware-overview.png
│   ├── system-architecture.png
│   ├── pcb-design.png
│   ├── 3d-assembly.png
│   ├── wearable.png
│   └── dashboard.png
│
├── Hardware/
│   ├── Schematics/
│   ├── PCB/
│   ├── Gerber/
│   ├── BOM/
│   └── Datasheets/
│
├── Firmware/
│   ├── ESP32_Node_1/
│   ├── ESP32_Node_2/
│   ├── Sensor_Drivers/
│   └── Configuration/
│
├── Wearable/
│   ├── Hardware/
│   ├── Firmware/
│   └── Interface/
│
├── Software/
│   ├── Dashboard/
│   ├── Firebase/
│   ├── Risk_Engine/
│   └── Application/
│
├── Mechanical/
│   ├── CAD/
│   ├── STEP/
│   └── Assembly/
│
├── Documentation/
│   ├── Architecture/
│   ├── Testing/
│   ├── Design_Decisions/
│   └── Progress_Logs/
│
└── LICENSE

Development Roadmap

- [x] Initial project concept.
- [x] Environmental safety research.
- [x] Multi-sensor architecture planning.
- [x] Dual ESP32 architecture.
- [x] KiCad schematic design.
- [x] PCB layout development.
- [x] 3D mechanical assembly design.
- [x] Firmware integration and validation.
- [x] Sensor calibration and testing.
- [x] Firebase integration testing.
- [x] Wearable integration.
- [x] Dashboard integration.
- [x] Complete system testing.
- [x] Real-world field validation.

Future Development

Future improvements are intended to include:

- AI-assisted environmental pattern recognition.
- Predictive risk analysis.
- Improved offline functionality.
- GPS-based location integration.
- Environmental risk mapping and heatmaps.
- Multilingual alert support.
- Extended wearable functionality.
- Historical environmental data analysis.
- Improved emergency communication.

Safety & Limitations

AIRDROP is an experimental environmental monitoring and early-warning prototype. It is not a certified life-safety device and should not replace official emergency warning systems or professional safety equipment.

Sensor readings and risk classifications require calibration, testing, and independent validation before being used in real-world safety decisions.

Project Vision

AIRDROP is built around one central idea:

Environmental safety information should reach people before a situation becomes an emergency.

By combining embedded systems, environmental sensors, wireless communication, cloud infrastructure, and wearable technology, AIRDROP aims to explore a smarter and more connected approach to environmental safety.

---

Project Information

Detail| Information
Project| AIRDROP
Developer| Samriddhi Gupta
Category| IoT / Hardware / Environmental Safety
Core Platform| ESP32
Cloud Infrastructure| Firebase
PCB Software| KiCad
Development Type| Hardware + Software

<p align="center">
  A Safer Tomorrow, Powered by AIRDROP.
</p>
