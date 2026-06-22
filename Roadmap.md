# Roadmap

A staged learning path through this repo — from absolute basics to IoT-connected projects. Each stage builds on the last; skipping ahead usually means more time debugging than learning.

> Recommended path: **Arduino Basics → DHT11 → HC-SR04 → OLED → MPU6050 → ESP32 WiFi → MQTT → IoT Projects**

> 📚 Beyond this path, [Component-Reference](Component-Reference/README.md) catalogs ~40 advanced & industrial parts (ECG, pulse oximetry, 9-DOF IMUs, optical ToF, LIDAR, current/force sensors, compute boards) with specs and datasheets.

---

## Stage 1: Arduino Basics

Learn:
- [ ] Digital Input
- [ ] Digital Output
- [ ] PWM
- [ ] Analog Input
- [ ] Serial Monitor

Examples:
- [ ] Blink LED
- [ ] Push Button
- [ ] Potentiometer Reading
- [ ] Servo Control
- [ ] Buzzer

→ See [`Microcontrollers/`](Microcontrollers/) for board-specific Blink LED sketches to start with.

---

## Stage 2: Basic Sensors

Start with these — they're cheap, easy to find, and forgiving to wire wrong.

### Light Sensor
- [x] [LDR](Sensors/Light/LDR/)
- [ ] Analog reading
- [ ] Voltage divider concept

Learn: analog values, calibration

### Temperature Sensor
- [x] [LM35](Sensors/Temperature/LM35/)
- [x] [DHT11](Sensors/Temperature/DHT11/)

Learn: analog-to-temperature conversion, libraries

### Distance Sensor
- [x] [HC-SR04](Sensors/Distance/HC-SR04/)

Learn: pulse timing, speed-of-sound calculation

### Motion Sensor
- [x] [PIR (HC-SR501)](Sensors/Motion/PIR-HC-SR501/)

Learn: digital inputs, event detection

→ See [`Sensors/`](Sensors/) for each sensor's folder.

---

## Stage 3: Communication Protocols

Very important — this is what unlocks every sensor beyond the basics.

### UART
Used for: Serial Monitor, GPS modules, Bluetooth modules
Learn: TX/RX, baud rate

### I2C
Used by: OLED displays, MPU6050, BMP280
Learn: SDA, SCL, device address

### SPI
Used by: SD cards, TFT displays, NRF24L01
Learn: MOSI, MISO, SCK, CS

→ See [`Communication/`](Communication/) for protocol explainers.

---

## Stage 4: Intermediate Sensors

### MPU6050 — Accelerometer + Gyroscope
Learn: I2C, motion tracking, filtering

### BMP280 — Pressure + Temperature
Learn: environmental sensing, altitude estimation

### RFID RC522
Learn: SPI, authentication

→ See [`Sensors/IMU/`](Sensors/IMU/), [`Sensors/Pressure/`](Sensors/Pressure/), [`Sensors/RFID/`](Sensors/RFID/).

---

## Stage 5: ESP32

After Arduino Uno fundamentals are solid.

### WiFi
- [ ] HTTP Requests
- [ ] Web Servers

### Bluetooth
- [ ] BLE

### OTA Updates
- [ ] Over-the-air firmware updates

→ See [`Microcontrollers/ESP32/`](Microcontrollers/ESP32/).

---

## First 10 Sensors/Modules (suggested order)

1. [x] [DHT11](Sensors/Temperature/DHT11/)
2. [x] [HC-SR04](Sensors/Distance/HC-SR04/)
3. [x] [LDR](Sensors/Light/LDR/)
4. [x] [PIR (HC-SR501)](Sensors/Motion/PIR-HC-SR501/)
5. [x] [LM35](Sensors/Temperature/LM35/)
6. [x] [BMP280](Sensors/Pressure/BMP280/)
7. [x] [MPU6050](Sensors/IMU/MPU6050/)
8. [x] [RC522 RFID](Sensors/RFID/RC522/)
9. [x] [MQ-2](Sensors/Gas/MQ-2/)
10. [x] [SSD1306 OLED](Sensors/Display/SSD1306-OLED/)

---

## Project Roadmap

### Beginner
- [ ] Automatic Night Lamp
- [ ] Temperature Monitor
- [ ] Parking Distance Sensor
- [ ] Motion Alarm

### Intermediate
- [ ] Smart Weather Station
- [ ] RFID Attendance System
- [ ] Gesture Controlled Light

### Advanced
- [ ] IoT Home Automation
- [ ] Smart Irrigation System
- [ ] Vehicle Tracking
- [ ] Industrial Monitoring Dashboard

→ Full table with sensor/module breakdown: [`Projects/README.md`](Projects/README.md)

---

## Datasheet Sources

Always download from official manufacturers — see [`Datasheets/README.md`](Datasheets/README.md) for the full list of links (Arduino, Microchip, Espressif, STMicroelectronics, Texas Instruments).
