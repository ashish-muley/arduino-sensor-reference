# LDR — Light Dependent Resistor (Photoresistor)

> 📝 **Reference code** — verify wiring for your specific module before relying on it.

📄 **Reference:** [Photoresistor / LDR basics (general)](https://en.wikipedia.org/wiki/Photoresistor)

## Description

An LDR (photoresistor) is a resistor whose resistance drops as light increases. It's the cheapest, simplest light sensor and the classic introduction to **analog reading** and the **voltage-divider** concept. Bright light → low resistance; darkness → high resistance.

| Parameter | Typical Value |
|---|---|
| Dark resistance | ~200 kΩ – 1 MΩ |
| Bright (lit) resistance | ~1 kΩ – 10 kΩ |
| Operating voltage | Any (passive component) |
| Output | Analog (via divider) |
| Response | Relative, not calibrated lux |

## Connection (Voltage Divider)

An LDR has no "output" pin by itself — you read the voltage at the midpoint of a divider formed by the LDR and a fixed resistor:

```
  5V ───[ LDR ]───┬───[ 10kΩ ]─── GND
                  │
                  └──→ A0
```

| Component | Connects To |
|---|---|
| LDR leg 1 | 5V |
| LDR leg 2 + resistor leg 1 | A0 (junction) |
| Resistor leg 2 | GND |

With this arrangement, **A0 rises as light increases**. Swap the LDR and resistor to invert it.

> Many LDR breakout **modules** include the resistor and a potentiometer already — they expose `AO` (analog) and `DO` (digital threshold) pins, like the MQ-gas modules.

## Working Principle

Photons striking the LDR's semiconductor material free charge carriers, lowering its resistance. In the divider, lower LDR resistance pulls the A0 node closer to 5 V. The Arduino reads this as a 0–1023 value representing relative brightness.

## Formula

```
V_A0 = 5V × R_fixed / (R_LDR + R_fixed)
```

## Libraries

None — uses `analogRead()`.

## Example Code

See [`Example_Code.ino`](Example_Code.ino) — prints a relative light value 0–1023.

## Notes & Gotchas

- The reading is **relative**, not calibrated lux. For real lux, use a digital sensor like the BH1750.
- Choose the fixed resistor to center the divider's swing for your light conditions (10 kΩ is a good default for indoor light).
- Used in the [Automatic Night Lamp](../../../Projects/Beginner/) project.
