# BMP280 — Barometric Pressure + Temperature (I²C/SPI)

> 📝 **Reference code** — verify wiring for your specific module before relying on it.

📄 **Datasheet:** [BMP280 (Bosch Sensortec)](https://www.bosch-sensortec.com/media/boschsensortec/downloads/datasheets/bst-bmp280-ds001.pdf)

## Description

The BMP280 is a precision barometric pressure and temperature sensor from Bosch. Because air pressure changes with altitude, it can also estimate height — useful for weather stations, drones, and indoor navigation. It speaks both I²C and SPI.

| Parameter | Value |
|---|---|
| Pressure range | 300 – 1100 hPa |
| Relative accuracy | ±0.12 hPa (~±1 m altitude) |
| Also measures | Temperature |
| Interface | I²C (0x76 default, 0x77 alt) or SPI |
| Operating voltage | 1.71 V – 3.6 V (breakouts add a regulator) |

> ⚠️ **BMP280 vs BME280:** The **BMP280 does *not* measure humidity.** If your board also reports humidity, it's a **BME280** — use the *Adafruit BME280* library instead. They look almost identical.

## Connection (I²C)

| BMP280 Pin | Uno/Nano | Mega | ESP32 |
|---|---|---|---|
| VCC | 3.3V (or 5V if regulated) | same | 3.3V |
| GND | GND | GND | GND |
| SCL | A5 | 21 | GPIO22 |
| SDA | A4 | 20 | GPIO21 |

## Working Principle

A piezo-resistive sensing element changes resistance with applied pressure; an onboard ADC and Bosch's calibration produce a compensated pressure reading. An internal IIR filter smooths out transient gusts/door-slams. Altitude is derived by comparing measured pressure against a known sea-level reference.

## Libraries

| Library (search exactly) | Author | Purpose |
|---|---|---|
| Adafruit BMP280 Library | Adafruit | Driver |
| Adafruit Unified Sensor | Adafruit | Dependency |
| Adafruit BusIO | Adafruit | Dependency |

## Example Code

See [`Example_Code.ino`](Example_Code.ino) — prints temperature, pressure (hPa), and estimated altitude.

## Notes & Gotchas

- Many breakouts default to I²C address **0x76**; some use **0x77**. The example tries 0x76 first — switch if `begin()` fails.
- For accurate **altitude**, feed `readAltitude()` the *current local* sea-level pressure (from a weather service), not the fixed 1013.25 default.
- Pairs naturally with a DHT22/SHT31 in the [Smart Weather Station](../../../Projects/Intermediate/) project (pressure + temperature + humidity).
