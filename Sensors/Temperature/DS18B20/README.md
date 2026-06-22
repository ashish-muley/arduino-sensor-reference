# DS18B20 — 1-Wire Digital Temperature Sensor

> 📝 **Reference code** — verify wiring for your specific module before relying on it.

📄 **Datasheet:** [DS18B20 (Analog Devices / Maxim)](https://www.analog.com/media/en/technical-documentation/data-sheets/DS18B20.pdf)

## Description

The DS18B20 is a digital temperature sensor on the Dallas **1-Wire** bus. Its standout feature: every sensor has a unique 64-bit ID burned in at the factory, so **many sensors can share a single data pin**. It's available as a bare TO-92 chip or a waterproof stainless-steel probe — making it the go-to for liquid, soil, and outdoor temperature.

| Parameter | Value |
|---|---|
| Range | −55 °C to +125 °C |
| Accuracy | ±0.5 °C (−10 °C to +85 °C) |
| Resolution | 9–12 bit (configurable) |
| Operating voltage | 3.0 V – 5.5 V |
| Bus | 1-Wire (Dallas/Maxim) |

## Connection

| DS18B20 Pin | Connects To | Notes |
|---|---|---|
| VCC | 5V (3.0–5.5 V) | |
| DATA | D2 | **4.7 kΩ pull-up between DATA and VCC is REQUIRED** |
| GND | GND | |

**Waterproof probe colors:** red = VCC, yellow (or blue) = DATA, black = GND.

```
  VCC ──────────────┬──────────────
                    │
              [4.7kΩ pull-up]
                    │
  DATA ─────────────┴──→ D2
  GND ──────────────────→ GND
```

## Working Principle

The Arduino addresses one or more DS18B20s on the shared 1-Wire bus by their unique IDs, sends a "convert temperature" command, then reads back a digital value. Because the bus is digital, it's far more noise-immune over long cable runs than an analog sensor like the LM35.

## Libraries

| Library (search exactly) | Author | Purpose |
|---|---|---|
| OneWire | Paul Stoffregen | 1-Wire bus protocol |
| DallasTemperature | Miles Burton | High-level DS18B20 driver |

## Example Code

See [`Example_Code.ino`](Example_Code.ino) — reads the first sensor on the bus.

## Notes & Gotchas

- The **4.7 kΩ pull-up resistor on the data line is mandatory**. Without it the bus simply won't respond — this is the #1 wiring mistake.
- To read multiple sensors, use `getTempCByIndex(1)`, `(2)`, etc., or address them by their unique IDs.
- The waterproof probe is ideal for the [Smart Irrigation](../../../Projects/Advanced/) and weather-station projects.
