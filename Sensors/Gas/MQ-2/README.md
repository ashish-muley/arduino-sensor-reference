# MQ-2 — Flammable Gas & Smoke Sensor

> 📝 **Reference code** — verify wiring for your specific module before relying on it.

📄 **Datasheet:** [MQ-2 (Pololu / Hanwei mirror)](https://www.pololu.com/file/0J309/MQ2.pdf)

## Description

The MQ-2 is a tin-dioxide (SnO₂) semiconductor gas sensor sensitive to LPG, propane, methane, hydrogen, alcohol, and smoke. It's the standard first gas sensor — cheap, and it teaches an important lesson: **gas sensors need warm-up time and calibration, not just code.**

| Parameter | Value |
|---|---|
| Detects | LPG, propane, methane, H₂, alcohol, smoke |
| Sensing range | ~300 – 10,000 ppm |
| Operating voltage | 5 V (heater) |
| Heater current | ~150 mA |
| Outputs | Analog (AO) + digital threshold (DO) |

## Connection

| MQ-2 Pin | Connects To | Notes |
|---|---|---|
| VCC | 5V | Heater needs 5 V — **do not** use 3.3 V |
| GND | GND | |
| AO | A0 | Analog gas level |
| DO | D2 | Digital HIGH/LOW per onboard potentiometer threshold |

```
  VCC → 5V    (heater ~150mA — power from 5V, common ground)
  GND → GND
  AO  → A0    (relative gas level)
  DO  → D2    (threshold trip, set by onboard pot)
```

## Working Principle

The SnO₂ sensing layer is heated by an internal coil. In clean air its conductivity is low; when reducing gases adsorb onto the heated surface, conductivity rises. The module converts that into an analog voltage (AO). The DO pin is just a comparator output that flips when AO crosses the level set by the onboard trim pot.

## ⚠️ This Sensor Needs Time, Not Just Code

- **First-ever use:** "burn-in" the heater for **24–48 hours** before readings stabilize.
- **Every session:** allow **~20 minutes** warm-up before trusting values.
- **Power:** the heater draws ~150 mA — power from 5 V with a common ground, never from a microcontroller pin.
- **PPM conversion** requires calibrating the sensor's Rs/Ro ratio against the datasheet curve. The raw analog value alone is **relative**, not a real ppm figure.

## Libraries

None required for the raw read. The **MQUnifiedsensor** library helps with ppm calibration if you go further.

## Example Code

See [`Example_Code.ino`](Example_Code.ino) — prints the relative analog level and the digital threshold state.

## Notes & Gotchas

- Treat the output as a **relative trend** unless you've done a proper calibration.
- Other MQ sensors swap in directly: **MQ-135** (air quality / CO₂-ish), **MQ-7** (carbon monoxide), **MQ-3** (alcohol).
- For accurate CO₂, a real NDIR sensor like the **SCD41** is the right tool — see [Component-Reference](../../../Component-Reference/README.md).
