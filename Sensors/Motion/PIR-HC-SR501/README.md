# PIR Motion Sensor (HC-SR501)

> 📝 **Reference code** — verify wiring for your specific module before relying on it.

📄 **Datasheet / reference:** [HC-SR501 module guide](https://www.mpja.com/download/31227sc.pdf)

## Description

A Passive Infrared (PIR) sensor detects motion by sensing changes in infrared (heat) radiation from moving bodies. The HC-SR501 is the most common hobby PIR module. Its output is a simple digital HIGH/LOW, so it's perfect for learning digital inputs and event-driven code.

| Parameter | Value |
|---|---|
| Detection range | ~3 m – 7 m (adjustable) |
| Detection angle | ~110°–120° |
| Operating voltage | 4.5 V – 20 V |
| Output logic level | 3.3 V |
| Warm-up time | 30–60 s after power-on |

## Connection

| HC-SR501 Pin | Connects To | Notes |
|---|---|---|
| VCC | 5V | Accepts 4.5–20 V |
| OUT | D2 | Digital HIGH when motion detected |
| GND | GND | |

```
  VCC → 5V
  OUT → D2   (idles LOW, goes HIGH on motion)
  GND → GND
```

## Onboard Adjustments

The HC-SR501 has two potentiometers and a jumper:
- **Sensitivity pot** — detection distance (~3–7 m)
- **Time-delay pot** — how long OUT stays HIGH after detection
- **Trigger jumper** — `H` (repeatable: keeps re-triggering while motion continues) vs `L` (single trigger)

## Working Principle

A pyroelectric sensor under the white Fresnel-lens dome detects infrared changes across its two halves. When a warm body moves across the field of view, the differential signal trips the onboard comparator, driving OUT high. A stationary heat source produces no *change*, so PIR only detects **movement**, not mere presence.

## Libraries

None — it's a digital input read with `digitalRead()`.

## Example Code

See [`Example_Code.ino`](Example_Code.ino) — lights the onboard LED and prints a message on motion.

## Notes & Gotchas

- **Give it 30–60 seconds to settle** after power-up; early readings are unreliable.
- It detects *change*, so someone standing perfectly still may stop triggering it.
- For presence/occupancy even when motionless, microwave radar modules (e.g. RCWL-0516) behave differently — noted in [Component-Reference](../../../Component-Reference/README.md).
- Used in the [Motion Alarm](../../../Projects/Beginner/) project.
