# Microcontrollers

Board-by-board reference, grouped by chip family. Each board folder includes specs, pinout notes, IDE setup steps, and a tested **Blink LED** sketch to confirm your environment is working before wiring up any sensor.

## Comparison Table

| Board | Family | Clock Speed | Operating Voltage | Digital I/O | Analog In | Flash | Built-in LED Pin | Wi-Fi/BT |
|---|---|---|---|---|---|---|---|---|
| [Arduino Uno](ATmega328P/Arduino-Uno/) | ATmega328P | 16 MHz | 5V | 14 | 6 | 32 KB | 13 | No |
| [Arduino Nano](ATmega328P/Arduino-Nano/) | ATmega328P | 16 MHz | 5V | 14 | 8 | 32 KB | 13 | No |
| [Arduino Mega 2560](ATmega328P/Arduino-Mega/) | ATmega2560 *(Mega family)* | 16 MHz | 5V | 54 | 16 | 256 KB | 13 | No |
| [ESP32 (DevKit)](ESP32/) | Xtensa LX6 dual-core | 240 MHz | 3.3V | ~34 (usable) | 18 (ADC, non-linear) | 4 MB (typical) | 2 *(varies by board)* | Yes (Wi-Fi + BT) |
| [ESP8266 / NodeMCU](ESP8266/) | Tensilica L106 | 80 MHz | 3.3V | ~11 (usable) | 1 | 4 MB (typical) | 2, active LOW | Yes (Wi-Fi only) |
| [STM32](STM32/) | ARM Cortex-M | *(varies)* | 3.3V | *(varies)* | *(varies)* | *(varies)* | *(varies)* | Varies by model |

> ⚠️ **5V vs 3.3V matters.** Uno/Nano/Mega are 5V logic. ESP32/ESP8266/STM32 are 3.3V logic and most pins are **not** 5V-tolerant. Don't connect a 5V sensor's signal pin directly to a 3.3V board's GPIO without a level shifter or voltage divider — check each sensor's README for voltage notes before wiring.

## Folder Layout

```
Microcontrollers/
├── ATmega328P/        Arduino Uno, Nano, Mega (classic 8-bit AVR boards)
├── ESP32/              Dual-core Wi-Fi + Bluetooth
├── ESP8266/            Budget Wi-Fi-only board
└── STM32/              ARM Cortex-M boards (added as the repo grows)
```

## How to Use This Section

1. Open the folder for your exact board
2. Read its README for the pinout, specs, and any board-specific IDE settings
3. Upload the Blink LED sketch inside its `Examples/` folder to confirm everything is wired and configured correctly

Once Blink works, move on to [`../Sensors/`](../Sensors/) — see [Roadmap.md](../Roadmap.md) for a suggested learning order.
