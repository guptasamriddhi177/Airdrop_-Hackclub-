# Dashboard Data Contract

Existing dashboard URL supplied by project owner:
https://foresight-alert-sphere.lovable.app/

The frontend should subscribe to:
`/devices/{deviceId}/latest`
and
`/devices/{deviceId}/status`

## Expected fields
- `timestamp`: Unix milliseconds or a documented consistent timestamp format.
- `environment.temperatureC`, `humidityPct`, `pressureHpa`, `gasResistanceOhm`, `status`.
- `motion.ax`, `ay`, `az`, `gx`, `gy`, `gz`, `status`.
- `indoorAirflow.value`, `unit`, `status`.
- `outdoorWind.speedMps`, `pulsesPerSecond`, `status`.
- `leak.zone1/zone2/zone3.wet`, `status`.
- `distance.channel1Cm`, `channel2Cm`.

## UI behavior
- Show `Unavailable` for null or stale values; never render null as 0.
- Display sensor freshness and device last-seen time.
- Distinguish sensor fault, disconnected device and threshold alert.
- Display raw/uncalibrated values as raw/uncalibrated.
- Do not label BME680 gas resistance as a toxic-gas concentration.
- Do not present an unvalidated composite score as a certified disaster prediction.

## Integration test
Publish a known test JSON object to a development database, then verify every card/graph on the Lovable dashboard reads the matching path and unit. Keep production credentials separate from development credentials.
