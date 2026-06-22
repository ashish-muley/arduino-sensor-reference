# Arduino Nano

A compact, breadboard-friendly board with the same core as the Uno — great for projects where space matters.

## Specs

| Property | Value |
|---|---|
| Microcontroller | ATmega328P |
| Operating Voltage | 5V |
| Input Voltage (recommended) | 7–12V |
| Digital I/O Pins | 14 (6 provide PWM output) |
| Analog Input Pins | 8 (A0–A7) |
| Flash Memory | 32 KB |
| SRAM | 2 KB |
| EEPROM | 1 KB |
| Clock Speed | 16 MHz |
| Built-in LED | Pin **13** |

## IDE Setup

- **Tools → Board:** `Arduino Nano`
- **Tools → Processor:** `ATmega328P` — if upload fails, try `ATmega328P (Old Bootloader)` (common on cheaper clone boards)
- **Tools → Port:** select the COM port shown when plugged in
- Clone Nano boards often use a **CH340** USB chip — install the [CH340 driver](http://www.wch.cn/download/CH341SER_ZIP.html) if the port doesn't appear

## Pinout Notes

Same pin layout logic as the Uno, but in a 30-pin DIP-style format with 2 extra analog pins (A6, A7) that are **analog-input only** — they can't be used as digital I/O.

## Test: Blink LED

Open [`Examples/Blink_LED.ino`](Examples/Blink_LED.ino) and upload it. The onboard LED next to pin 13 should blink on/off every second. No external wiring needed.
