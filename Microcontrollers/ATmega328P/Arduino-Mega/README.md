# Arduino Mega 2560

The board to reach for when a project needs many I/O pins, multiple hardware serial ports, or more memory than an Uno can offer.

## Specs

| Property | Value |
|---|---|
| Microcontroller | ATmega2560 |
| Operating Voltage | 5V |
| Input Voltage (recommended) | 7–12V |
| Digital I/O Pins | 54 (15 provide PWM output) |
| Analog Input Pins | 16 (A0–A15) |
| Flash Memory | 256 KB |
| SRAM | 8 KB |
| EEPROM | 4 KB |
| Clock Speed | 16 MHz |
| Hardware Serial Ports | 4 (Serial, Serial1, Serial2, Serial3) |
| Built-in LED | Pin **13** |

## IDE Setup

- **Tools → Board:** `Arduino Mega or Mega 2560`
- **Tools → Processor:** `ATmega2560 (Mega 2560)`
- **Tools → Port:** select the COM port shown when plugged in

## Why Choose Mega Over Uno

- Multiple sensors/modules needing many digital pins simultaneously (e.g. several ultrasonic sensors, LCD + keyboard + sensors together)
- Projects needing more than one hardware serial port (e.g. talking to a GPS module on Serial1 while debugging over Serial)
- Larger sketches that exceed the Uno's 32 KB flash

## Test: Blink LED

Open [`Examples/Blink_LED.ino`](Examples/Blink_LED.ino) and upload it. The onboard LED next to pin 13 should blink on/off every second. No external wiring needed.
