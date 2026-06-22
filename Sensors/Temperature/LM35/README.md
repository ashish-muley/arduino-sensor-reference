# LM35 — Analog Temperature Sensor

> 📝 **Reference code** — verify wiring for your specific module before relying on it.

📄 **Datasheet:** [LM35 (Texas Instruments)](https://www.ti.com/lit/ds/symlink/lm35.pdf)

## Description

The LM35 is a precision analog temperature sensor with a beautifully simple output: a linear **10 mV per °C**. No library, no protocol — just read the analog voltage and multiply. It's the classic sensor for teaching analog-to-physical-quantity conversion.

| Parameter | Value |
|---|---|
| Output scale | 10 mV / °C (linear) |
| Range (basic LM35) | 0 °C to 100 °C (full part: −55 °C to 150 °C with extra wiring) |
| Accuracy | ±0.5 °C (typical at 25 °C) |
| Operating voltage | 4 V – 30 V |
| Output type | Analog voltage |

## Connection

The LM35 in the common TO-92 package, **flat face toward you, legs pointing down**:

| LM35 Pin (left→right) | Connects To |
|---|---|
| +Vs (left) | 5V |
| Vout (middle) | A0 |
| GND (right) | GND |

```
    flat face
   ┌─────────┐
   │  LM35   │
   └─┬──┬──┬─┘
    +Vs │  GND
        Vout → A0
```

## Working Principle

The LM35 outputs a voltage directly proportional to temperature in Celsius. At 25 °C it outputs 250 mV; at 30 °C, 300 mV. The Arduino reads this with `analogRead()`, converts the 0–1023 count to volts, then multiplies by 100 (because 10 mV = 1 °C → 1 V = 100 °C).

## Formula

```
voltage (V) = analogRead × (5.0 / 1023)      // 5V ref, 10-bit ADC
temperature (°C) = voltage × 100
```

## Libraries

None — uses only the built-in `analogRead()`.

## Example Code

See [`Example_Code.ino`](Example_Code.ino).

## Notes & Gotchas

- The conversion assumes a **5 V reference and 10-bit ADC** (Uno/Nano/Mega). On ESP32/ESP8266 the reference is 3.3 V, the ADC differs, and the ESP32 ADC is non-linear — recalibrate before trusting values there.
- Analog noise can make the last digit jitter; averaging several reads smooths it.
- For better noise immunity and multiple sensors on one wire, consider the digital [DS18B20](../DS18B20/) instead.
