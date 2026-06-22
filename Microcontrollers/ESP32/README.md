# ESP32

A dual-core Wi-Fi + Bluetooth microcontroller — the go-to choice once a project needs networking, more processing power, or more I/O than an Uno offers.

## Specs

| Property | Value |
|---|---|
| Microcontroller | Xtensa LX6, dual-core |
| Operating Voltage | 3.3V |
| Input Voltage (via USB) | 5V (regulated onboard to 3.3V) |
| Digital I/O Pins | ~34 usable GPIOs (varies by dev board) |
| Analog Input Pins | Up to 18 (ADC1 + ADC2, non-linear response — see note below) |
| Flash Memory | 4 MB (typical dev boards; varies) |
| Clock Speed | 240 MHz |
| Wireless | Wi-Fi (802.11 b/g/n) + Bluetooth Classic/BLE |
| Built-in LED | **Pin varies by board** — see below |

> ⚠️ **3.3V logic, not 5V-tolerant on most pins.** Connecting a 5V sensor signal directly to most ESP32 GPIOs can damage the pin. Check each sensor's README for level-shifting or voltage-divider notes before wiring.

## Important: Onboard LED Pin Varies by Board

Unlike Uno/Nano/Mega, ESP32 dev boards from different manufacturers wire the onboard LED to different GPIOs — there's no universal standard:

| Board variant | Common LED Pin |
|---|---|
| Most generic "ESP32 DevKit" boards | GPIO 2 |
| ESP32-WROOM-32 DevKitC (some revisions) | No onboard LED, or GPIO 2 |
| ESP32-S2/S3 boards | Often GPIO 15, 18, or 48 — check your specific board's pinout |

If `LED_BUILTIN` isn't defined for your board variant, or the Blink sketch doesn't blink anything, check your board's silkscreen/datasheet for which GPIO drives the onboard LED, and edit the pin number in the sketch.

## IDE Setup

- Make sure ESP32 board support is installed — see [docs/getting-started.md](../../docs/getting-started.md#3-add-esp32--esp8266-board-support)
- **Tools → Board → ESP32 Arduino →** select your exact variant (e.g. `ESP32 Dev Module`)
- **Tools → Port:** select the COM port — install [CP210x](https://www.silabs.com/developers/usb-to-uart-bridge-vcp-drivers) or [CH340](http://www.wch.cn/download/CH341SER_ZIP.html) drivers if it doesn't appear
- **Tools → Upload Speed:** `115200` is safest to start

## Test: Blink LED

Open [`Examples/Blink_LED.ino`](Examples/Blink_LED.ino) and upload it. If nothing blinks, confirm your board's actual LED pin (see table above) and update the `LED_PIN` value in the sketch.
