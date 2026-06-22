# Arduino Sensor Reference

A comprehensive, organized reference for Arduino-compatible sensor tutorials, wiring diagrams, and code snippets. Built for Arduino, ESP32, and ESP8266 — with datasheet summaries and clear initialization steps to streamline your IoT and embedded systems projects.

![Platform](https://img.shields.io/badge/platform-Arduino%20%7C%20ESP32%20%7C%20ESP8266-00979D)
![License](https://img.shields.io/badge/license-MIT-blue)
![Status](https://img.shields.io/badge/status-actively%20growing-brightgreen)
![PRs](https://img.shields.io/badge/contributions-welcome-orange)

> 🌱 This repository is updated regularly as new boards and sensors are added, tested, and documented. Star ⭐ it to keep track of new additions.

---

## 📖 What's Inside

This repo is built for **beginners and hobbyists** who want working, tested code instead of digging through forums. Every sensor entry includes wiring instructions, required libraries, and a working sketch — not just raw code.

| Folder | What you'll find |
|---|---|
| [`docs/`](docs/) | Arduino IDE setup, board manager config, library installation guide, troubleshooting |
| [`01-microcontrollers/`](01-microcontrollers/) | Board-specific basics — pinouts, specs, and Blink LED test sketches for every board |
| [`02-sensors/`](02-sensors/) | Sensor-by-sensor folders with wiring diagrams, datasheets, and code for multiple boards |
| [`03-libraries-reference/`](03-libraries-reference/) | Master list of every Arduino library used in this repo, with install instructions |
| [`04-projects/`](04-projects/) | Combined multi-sensor projects built using the code above |

---

## 🚀 New Here? Start in This Order

1. **[Install the Arduino IDE & set up your board](docs/getting-started.md)** — covers IDE download, board manager URLs for ESP32/ESP8266, and driver installation
2. **[Learn how to install libraries](docs/library-installation-guide.md)** — Library Manager vs. manual `.zip` installs
3. **Pick your microcontroller** in [`01-microcontrollers/`](01-microcontrollers/) and run the Blink LED test to confirm your IDE, board, and drivers are working
4. **Pick a sensor** in [`02-sensors/`](02-sensors/) and wire it up using the README in that sensor's folder
5. Stuck? Check **[troubleshooting.md](docs/troubleshooting.md)**

---

## 🔌 Supported Microcontrollers

| Board | Status | Onboard LED Pin |
|---|---|---|
| Arduino Uno | ✅ Tested | 13 |
| Arduino Nano | ✅ Tested | 13 |
| Arduino Mega 2560 | ✅ Tested | 13 |
| ESP32 (DevKit) | ✅ Tested | 2 (varies by board) |
| ESP8266 / NodeMCU | ✅ Tested | 2 (D4, active LOW) |

*(List grows as new boards are added — see [`01-microcontrollers/`](01-microcontrollers/) for full details and comparison table.)*

## 🌡️ Supported Sensors

| Sensor | Type | Tested On | Folder |
|---|---|---|---|
| *(coming soon)* | | | |

*(This table is updated every time a new sensor is added. Full index lives in [`02-sensors/README.md`](02-sensors/README.md).)*

---

## 🗂 Repository Structure

```
arduino-sensor-reference/
├── docs/                       Setup guides, library install, troubleshooting
├── 01-microcontrollers/        Board basics + Blink LED per board
├── 02-sensors/                 Sensor wiring, datasheets, and code per board
├── 03-libraries-reference/     Index of all libraries used across this repo
└── 04-projects/                Multi-sensor combined builds
```

---

## 🤝 Contributing

Found an issue or want to add a sensor? Open an [issue](../../issues) or pull request. Please follow the existing folder pattern (README + code + datasheet where applicable) so the repo stays consistent.

## 📄 License

This project is licensed under the [MIT License](LICENSE) — free to use, modify, and share.

---

<p align="center">Maintained by <a href="https://github.com/ashish-muley">ashish-muley</a></p>
