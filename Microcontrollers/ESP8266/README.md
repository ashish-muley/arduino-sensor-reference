# ESP8266 / NodeMCU

A budget-friendly Wi-Fi microcontroller — slightly more limited in I/O and processing than the ESP32, but very capable for IoT sensor projects.

## Specs

| Property | Value |
|---|---|
| Microcontroller | Tensilica L106 (32-bit) |
| Operating Voltage | 3.3V |
| Input Voltage (via USB) | 5V (regulated onboard to 3.3V) |
| Digital I/O Pins | ~11 usable GPIOs (NodeMCU board; several are reserved for flash/boot) |
| Analog Input Pins | 1 (A0, 0–1V range — note below) |
| Flash Memory | 4 MB (typical NodeMCU boards) |
| Clock Speed | 80 MHz (can run at 160 MHz) |
| Wireless | Wi-Fi (802.11 b/g/n) only — no Bluetooth |
| Built-in LED | **GPIO 2 (labeled D4 on NodeMCU), active LOW** |

> ⚠️ **3.3V logic, not 5V-tolerant.** Same caution as ESP32 — check sensor READMEs before connecting 5V sensor outputs directly.
>
> ⚠️ **A0 analog input is limited to 0–1V** on the NodeMCU module (it has an onboard voltage divider already tuned for the ESP8266's native 0–1V ADC range) — don't assume it reads 0–3.3V like other boards' analog pins.

## Important: Built-in LED is Active LOW

Unlike Uno/Mega/ESP32, the NodeMCU's onboard LED turns **ON** when the pin is set **LOW**, and off when set **HIGH** — backwards from the usual convention. This is reflected in the Blink sketch below. If you write `HIGH` expecting the LED on (like other boards), it'll actually be off.

## IDE Setup

- Make sure ESP8266 board support is installed — see [docs/getting-started.md](../../docs/getting-started.md#3-add-esp32--esp8266-board-support)
- **Tools → Board → ESP8266 Boards →** select `NodeMCU 1.0 (ESP-12E Module)` (most common variant)
- **Tools → Port:** select the COM port — install [CH340](http://www.wch.cn/download/CH341SER_ZIP.html) driver if it doesn't appear (most NodeMCU boards use this chip)
- **Tools → Upload Speed:** `115200` is safest to start

## Test: Blink LED

Open [`Examples/Blink_LED.ino`](Examples/Blink_LED.ino) and upload it. The onboard LED (near the USB port, labeled D4/GPIO2) should blink every second.
