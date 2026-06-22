# HC-SR04 — Ultrasonic Distance Sensor

> 📝 **Reference code** — verify wiring for your specific module before relying on it.

📄 **Datasheet:** [HC-SR04 (SparkFun)](https://cdn.sparkfun.com/datasheets/Sensors/Proximity/HCSR04.pdf)

## Description

The HC-SR04 is the ubiquitous, cheap ultrasonic distance sensor — the one in nearly every beginner robotics kit. It measures 2–400 cm by bouncing a 40 kHz sound pulse off a surface and timing the echo. No library needed; just trigger and time.

| Parameter | Value |
|---|---|
| Range | 2 cm – 400 cm |
| Resolution | ~0.3 cm |
| Measuring angle | ~15° |
| Operating voltage | 5 V |
| Frequency | 40 kHz |

## Connection

| HC-SR04 Pin | Connects To | Notes |
|---|---|---|
| VCC | 5V | |
| TRIG | D9 | Trigger output from Arduino |
| ECHO | D10 | Echo input to Arduino |
| GND | GND | |

> ⚠️ **3.3 V boards (ESP32/ESP8266):** the ECHO pin outputs **5 V** and is not 3.3 V-safe. Put a voltage divider (e.g. 1 kΩ + 2 kΩ) on ECHO, or use a logic-level shifter, or you risk damaging the GPIO.

```
  VCC  → 5V
  TRIG → D9  ──(10µs pulse out)
  ECHO → D10 ──(echo pulse in)   [divider to 3.3V if on ESP32/8266]
  GND  → GND
```

## Working Principle

A 10 µs HIGH pulse on **TRIG** makes the module emit an 8-cycle 40 kHz ultrasonic burst. The **ECHO** pin then goes HIGH for exactly as long as the sound takes to travel to the object and back. Multiply that time by the speed of sound and divide by two (out-and-back) to get distance.

## Formula

```
distance (cm) = echo_time (µs) × 0.0343 / 2
```
`0.0343 cm/µs` is the speed of sound at ~20 °C. For precision, the speed varies with temperature: `331.4 + 0.606 × T(°C)` m/s.

## Libraries

None required (uses `pulseIn()`). Optionally the **NewPing** library handles timeouts and multiple sensors more gracefully.

## Example Code

See [`Example_Code.ino`](Example_Code.ino) — prints distance in cm.

## Notes & Gotchas

- Soft or angled surfaces absorb/deflect the pulse → null or wrong readings. Works best against hard, flat, perpendicular surfaces.
- The ~15° beam is wide — it detects the *nearest* object in a cone, not a precise point.
- For narrow-beam, reflectance-independent precision, an optical Time-of-Flight sensor like the **VL53L1X** is far better — see [Component-Reference](../../../Component-Reference/README.md).
- Used in the [Parking Distance Sensor](../../../Projects/Beginner/) project.
