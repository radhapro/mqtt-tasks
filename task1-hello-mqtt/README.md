# Task 1 - Hello MQTT

## Kya Kiya
ESP32 se HiveMQ Cloud pe message publish aur subscribe kiya

## Functions Used
- connect() - HiveMQ server se connection banaya
- publish() - "Hello from ESP32!" message bheja
- subscribe() - test/hello topic join kiya
- loop() - connection alive rakha

## Flow
ESP32 → publish → HiveMQ Cloud → deliver → ESP32/Browser

## Files
- main.cpp - ESP32 ka code
- platformio.ini - PlatformIO config
- mqtt_dashboard.html - Browser pe live messages dekhne ka webpage

## Screenshots
### Serial Monitor
![Serial Monitor](images/serial_monitor.png)

### HiveMQ Web Client
![HiveMQ](images/hivemq.png)

### Browser Dashboard
![Dashboard](images/dashboard.png)