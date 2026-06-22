# Arduino Uno

The most common Arduino board — a good default choice for learning and most sensor projects.

## Specs

| Property | Value |
|---|---|
| Microcontroller | ATmega328P |
| Operating Voltage | 5V |
| Input Voltage (recommended) | 7–12V (via barrel jack/Vin) |
| Digital I/O Pins | 14 (6 provide PWM output) |
| Analog Input Pins | 6 (A0–A5) |
| Flash Memory | 32 KB |
| SRAM | 2 KB |
| EEPROM | 1 KB |
| Clock Speed | 16 MHz |
| Built-in LED | Pin **13** |

## IDE Setup

- **Tools → Board:** `Arduino Uno`
- **Tools → Port:** select the COM port that appears when plugged in (driver is usually automatic on Windows 10/11, macOS, Linux)
- **Tools → Programmer:** leave as default (`AVRISP mkII`) unless using an external programmer

## Pinout Reference

```
                    ___________________
                   |  [USB]    [POWER] |
            D13/SCK|                   |
             D12   |                   |
        ~D11/MOSI  |                   |
             D10   |       ARDUINO     |
              D9   |         UNO       |
              D8   |                   |
              D7   |___________________|
              D6   |
              D5   |   A0  A1  A2  A3  A4  A5
              D4   |
              D3   |
              D2   |
             TX→D1 |
             RX←D0 |
```
*(Simplified — see the official [Arduino Uno pinout diagram](https://docs.arduino.cc/hardware/uno-rev3/) for full detail including AREF, ICSP, and power pins.)*

## Test: Blink LED

Open [`01-blink-led/blink_led.ino`](01-blink-led/blink_led.ino) and upload it. The onboard LED next to pin 13 should blink on/off every second. No external wiring needed — this only tests the onboard LED.
