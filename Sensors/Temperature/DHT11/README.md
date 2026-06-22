# DHT11 — Temperature & Humidity

> 📝 **Reference code** — verify wiring for your specific module before relying on it.

📄 **Datasheet:** [DHT11 / DHT22 / AM2302 (Mouser)](https://www.mouser.com/datasheet/2/737/dht-932870.pdf)

## Description

The DHT11 is the cheaper, lower-precision sibling of the DHT22. Same single-wire protocol and same Arduino library — only the sensor type and accuracy differ. It's a great first temperature/humidity sensor for learning because it's inexpensive and forgiving.

| Parameter | Value |
|---|---|
| Temperature range | 0 °C to 50 °C (±2 °C) |
| Humidity range | 20–90% RH (±5%) |
| Operating voltage | 3.3 V – 5.5 V |
| Output | Digital, proprietary single-wire |
| Minimum read interval | ~1 second |

**DHT11 vs DHT22:** Use the DHT11 to learn cheaply; switch to the [DHT22](../DHT22/) when you need the wider range and tighter accuracy. The wiring and code are identical apart from `#define DHTTYPE`.

## Connection

| DHT11 Pin | Connects To | Notes |
|---|---|---|
| VCC | 5V (or 3.3V on ESP32/ESP8266) | |
| DATA | D2 | 10 kΩ pull-up to VCC (often built into breakout boards) |
| GND | GND | |

> 3-pin DHT11 breakout boards already include the pull-up resistor and are labeled `S` (signal), `+`/middle (VCC), `−` (GND). The bare 4-pin sensor needs an external 10 kΩ pull-up.

## Working Principle

Identical to the DHT22 — a humidity-sensitive capacitor and a thermistor, sampled by an onboard MCU that outputs a calibrated 40-bit digital frame. The lower price comes from coarser resolution (whole-degree / whole-percent steps) and a narrower range.

## Libraries

| Library (search exactly) | Author | Purpose |
|---|---|---|
| DHT sensor library | Adafruit | Core driver |
| Adafruit Unified Sensor | Adafruit | Dependency |

## Example Code

See [`Example_Code.ino`](Example_Code.ino) — prints temperature (°C) and humidity (%) about once per second.

## Notes & Gotchas

- DHT11 reports in **whole-number steps** — don't expect decimal precision.
- Don't poll faster than ~1 Hz.
- Not suitable for sub-zero temperatures (range starts at 0 °C) — use the DHT22 or a DS18B20 for cold environments.
