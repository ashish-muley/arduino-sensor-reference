# Libraries Reference

Every Arduino library used across this repository — the exact name to search for in Library Manager, the author (to disambiguate similar names), what it's for, and how to install it.

See [docs/library-installation-guide.md](../docs/library-installation-guide.md) for step-by-step install instructions. Most install via **Sketch → Include Library → Manage Libraries**.

## Index

| Library (search exactly) | Author | Used By | Install |
|---|---|---|---|
| DHT sensor library | Adafruit | DHT11, DHT22 | Library Manager |
| Adafruit Unified Sensor | Adafruit | DHT11/22, MPU6050, BMP280 (dependency) | Library Manager |
| OneWire | Paul Stoffregen | DS18B20 | Library Manager |
| DallasTemperature | Miles Burton | DS18B20 | Library Manager |
| Adafruit MPU6050 | Adafruit | MPU6050 | Library Manager |
| Adafruit BusIO | Adafruit | MPU6050, BMP280, SSD1306 (dependency) | Library Manager |
| Adafruit BMP280 Library | Adafruit | BMP280 | Library Manager |
| MFRC522 | GithubCommunity (miguelbalboa) | RC522 RFID | Library Manager |
| Adafruit SSD1306 | Adafruit | SSD1306 OLED | Library Manager |
| Adafruit GFX Library | Adafruit | SSD1306 OLED | Library Manager |

## Sensors That Need No Library

These use only built-in Arduino functions (`analogRead`, `digitalRead`, `pulseIn`):

| Sensor | Built-in function used |
|---|---|
| LM35 | `analogRead()` |
| LDR | `analogRead()` |
| MQ-2 | `analogRead()` + `digitalRead()` |
| HC-SR04 | `pulseIn()` |
| PIR (HC-SR501) | `digitalRead()` |

## Dependency Note

The Adafruit driver libraries (MPU6050, BMP280, SSD1306) all depend on **Adafruit Unified Sensor** and/or **Adafruit BusIO**. When you install the main library, the IDE usually prompts to install these too — click **Install All**. If a sketch fails to compile with a missing-header error, installing these dependencies manually is the fix.

*Updated whenever a new sensor is added.*
