# Arduino Sensor Reference

A comprehensive, organized reference for embedded systems and IoT — covering microcontrollers, sensors, communication protocols, and progressively harder projects, built on Arduino, ESP32, ESP8266, and STM32.

![Platform](https://img.shields.io/badge/platform-Arduino%20%7C%20ESP32%20%7C%20ESP8266%20%7C%20STM32-00979D)
![License](https://img.shields.io/badge/license-MIT-blue)
![Status](https://img.shields.io/badge/status-actively%20growing-brightgreen)
![PRs](https://img.shields.io/badge/contributions-welcome-orange)

> 🌱 Updated regularly as new boards, sensors, and projects are added and tested. Star ⭐ to keep track.

---

## Learning Path

```
Arduino Basics → DHT11 → HC-SR04 → OLED → MPU6050 → ESP32 WiFi → MQTT → IoT Projects
```

This repo is structured so each stage builds on the last — see **[Roadmap.md](Roadmap.md)** for the full staged path with checkboxes.

---

## Repository Structure

```
arduino-sensor-reference/
│
├── README.md
├── Roadmap.md                  Staged learning path, beginner → advanced
│
├── Sensors/                    Sensor-by-sensor: wiring, datasheets, working code
│   ├── Temperature/
│   ├── Distance/
│   ├── Motion/
│   ├── Light/
│   ├── Gas/
│   ├── IMU/
│   ├── Pressure/
│   ├── RFID/
│   └── Display/
│
├── Microcontrollers/           Board-by-board: specs, pinouts, Blink LED tests
│   ├── ATmega328P/             Arduino Uno, Nano, Mega
│   ├── ESP32/
│   ├── ESP8266/
│   └── STM32/
│
├── Communication/               Protocol explainers: how sensors actually talk
│   ├── UART/
│   ├── I2C/
│   ├── SPI/
│   └── CAN/
│
├── Projects/                   Combined multi-sensor builds, by difficulty
│   ├── Beginner/
│   ├── Intermediate/
│   └── Advanced/
│
├── Component-Reference/         Catalog of ~40 advanced & industrial parts
│                                 (ECG, ToF, LIDAR, 9-DOF IMU, compute boards...)
├── Datasheets/                 Index + official manufacturer source links
└── Libraries-Reference/         Every library used in this repo, in one table
```

---

## Every Sensor Folder Follows the Same Pattern

```
Sensor-Name/
├── README.md          Description, pinout, working principle, formula, example
├── Wiring.png           Wiring/breadboard diagram
├── Example_Code.ino     Tested working sketch
├── Datasheet.pdf         Official datasheet
└── Notes.md              Calibration tips, gotchas, common mistakes
```

So once you've used one sensor folder, you already know how to navigate every other one.

---

## New Here? Start in This Order

1. **[Install the Arduino IDE & set up your board](docs/getting-started.md)** — IDE download, board manager URLs for ESP32/ESP8266, drivers
2. **[Learn how to install libraries](docs/library-installation-guide.md)** — Library Manager vs. manual `.zip` installs
3. **Pick your microcontroller** in [`Microcontrollers/`](Microcontrollers/) and run the Blink LED test
4. **Follow [Roadmap.md](Roadmap.md)** stage by stage — basics → sensors → communication protocols → intermediate sensors → ESP32 → projects
5. Stuck? Check **[docs/troubleshooting.md](docs/troubleshooting.md)**

---

## Supported Microcontrollers

| Board | Family | Status | Onboard LED Pin |
|---|---|---|---|
| Arduino Uno | ATmega328P | ✅ Tested | 13 |
| Arduino Nano | ATmega328P | ✅ Tested | 13 |
| Arduino Mega 2560 | ATmega2560 | ✅ Tested | 13 |
| ESP32 (DevKit) | Xtensa LX6 | ✅ Tested | 2 (varies by board) |
| ESP8266 / NodeMCU | Tensilica L106 | ✅ Tested | 2 (D4, active LOW) |
| STM32 | ARM Cortex-M | 🔜 Planned | — |

Full comparison table: [`Microcontrollers/README.md`](Microcontrollers/README.md)

## Sensors Covered So Far

| Sensor | Category | Interface | Status |
|---|---|---|---|
| [LM35](Sensors/Temperature/LM35/) | Temperature | Analog | 📝 Reference |
| [DHT11](Sensors/Temperature/DHT11/) | Temperature | Digital | 📝 Reference |
| [DHT22](Sensors/Temperature/DHT22/) | Temperature | Digital | 📝 Reference |
| [DS18B20](Sensors/Temperature/DS18B20/) | Temperature | 1-Wire | 📝 Reference |
| [HC-SR04](Sensors/Distance/HC-SR04/) | Distance | Ultrasonic | 📝 Reference |
| [PIR (HC-SR501)](Sensors/Motion/PIR-HC-SR501/) | Motion | Digital | 📝 Reference |
| [LDR](Sensors/Light/LDR/) | Light | Analog | 📝 Reference |
| [MQ-2](Sensors/Gas/MQ-2/) | Gas | Analog | 📝 Reference |
| [MPU6050](Sensors/IMU/MPU6050/) | IMU | I²C | 📝 Reference |
| [BMP280](Sensors/Pressure/BMP280/) | Pressure | I²C | 📝 Reference |
| [RC522](Sensors/RFID/RC522/) | RFID | SPI | 📝 Reference |
| [SSD1306 OLED](Sensors/Display/SSD1306-OLED/) | Display | I²C | 📝 Reference |

> 📝 **Reference** = code written from manufacturer datasheets and standard libraries, with full wiring and notes — but not yet bench-tested here. Boards above are ✅ Tested because they were verified on hardware.

Full index: [`Sensors/README.md`](Sensors/README.md) · ~40 advanced/industrial parts cataloged in [`Component-Reference/`](Component-Reference/README.md)

---

## Contributing

Found an issue or want to add a sensor? Open an [issue](../../issues) or pull request. Please follow the existing folder pattern so the repo stays consistent — see [`Sensors/README.md`](Sensors/README.md) for the standard layout.

## License

Licensed under the [MIT License](LICENSE) — free to use, modify, and share.

---

<p align="center">Maintained by <a href="https://github.com/ashish-muley">ashish-muley</a></p>
