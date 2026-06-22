# Microcontrollers

Board-by-board basics: specs, pinouts, and a Blink LED sketch to confirm your setup works before wiring up any sensor.

## Comparison Table

| Board | MCU | Clock Speed | Operating Voltage | Digital I/O | Analog In | Flash | Built-in LED Pin | Wi-Fi/BT |
|---|---|---|---|---|---|---|---|---|
| [Arduino Uno](arduino-uno/) | ATmega328P | 16 MHz | 5V | 14 | 6 | 32 KB | 13 | No |
| [Arduino Nano](arduino-nano/) | ATmega328P | 16 MHz | 5V | 14 | 8 | 32 KB | 13 | No |
| [Arduino Mega 2560](arduino-mega/) | ATmega2560 | 16 MHz | 5V | 54 | 16 | 256 KB | 13 | No |
| [ESP32 (DevKit)](esp32/) | Xtensa LX6 dual-core | 240 MHz | 3.3V | ~34 (usable) | 18 (ADC, non-linear) | 4 MB (typical) | 2 *(varies by board)* | Yes (Wi-Fi + BT) |
| [ESP8266 / NodeMCU](esp8266-nodemcu/) | Tensilica L106 | 80 MHz | 3.3V | ~11 (usable) | 1 | 4 MB (typical) | 2, active LOW | Yes (Wi-Fi only) |

> ⚠️ **5V vs 3.3V matters.** Uno/Nano/Mega are 5V logic. ESP32/ESP8266 are 3.3V logic and most pins are **not** 5V-tolerant. Don't connect a 5V sensor's signal pin directly to an ESP32/ESP8266 GPIO without a level shifter or voltage divider — check each sensor's README for voltage notes before wiring.

## How to Use This Section

1. Open the folder for your exact board
2. Read its README for the pinout and any board-specific IDE settings
3. Upload the Blink LED sketch inside `01-blink-led/` to confirm everything is wired and configured correctly

Once Blink works, move on to [`02-sensors/`](../02-sensors/).
