# MPU6050 — 6-Axis Accelerometer + Gyroscope (I²C)

> 📝 **Reference code** — verify wiring for your specific module before relying on it.

📄 **Datasheet:** [MPU-6050 (InvenSense)](https://www.handsontec.com/dataspecs/MPU6050.pdf)

## Description

The MPU6050 is a 6-DOF (degrees of freedom) MotionTracking device: a 3-axis MEMS accelerometer plus a 3-axis MEMS gyroscope on one chip, talking over I²C. It's the standard intro to inertial sensing, sensor fusion, and the I²C bus — the foundation for self-balancing robots, drones, and gesture control.

| Parameter | Value |
|---|---|
| Axes | 3 accel + 3 gyro (6-DOF) |
| Accel range | ±2g / ±4g / ±8g / ±16g (selectable) |
| Gyro range | ±250 / ±500 / ±1000 / ±2000 °/s |
| ADC | 16-bit per channel |
| Interface | I²C (address 0x68, or 0x69 if AD0 = HIGH) |
| Operating voltage | 3.3 V (modules usually have a 5 V-tolerant regulator) |

## Connection

| MPU6050 Pin | Uno/Nano | Mega | ESP32 | NodeMCU |
|---|---|---|---|---|
| VCC | 5V or 3.3V | 5V/3.3V | 3.3V | 3.3V |
| GND | GND | GND | GND | GND |
| SCL | A5 | 21 | GPIO22 | D1 |
| SDA | A4 | 20 | GPIO21 | D2 |

(AD0 left unconnected → address 0x68. Tie AD0 to VCC for 0x69 to run two on one bus.)

## Working Principle

The accelerometer measures linear acceleration (including gravity) via tiny moving masses whose displacement changes capacitance. The gyroscope measures angular rate using the **Coriolis effect** on a vibrating proof mass. Each axis has its own 16-bit ADC, so all six channels are sampled simultaneously. Combining accel + gyro (sensor fusion / complementary or Kalman filtering) yields stable tilt/orientation.

## Libraries

| Library (search exactly) | Author | Purpose |
|---|---|---|
| Adafruit MPU6050 | Adafruit | High-level driver |
| Adafruit Unified Sensor | Adafruit | Dependency |
| Adafruit BusIO | Adafruit | Dependency |

## Example Code

See [`Example_Code.ino`](Example_Code.ino) — prints accel (m/s²), gyro (rad/s), and temperature.

## Notes & Gotchas

- Raw accel/gyro values **drift and jitter** — useful orientation needs filtering. The gyro drifts over time; the accelerometer is noisy but absolute. Fusing them is the whole point.
- If `begin()` fails, run an **I²C scanner** sketch to confirm the address (0x68 vs 0x69).
- For *absolute* orientation without writing your own filter, the **BNO055** has an onboard fusion processor — see [Component-Reference](../../../Component-Reference/README.md).
- Used in the [Gesture Controlled Light](../../../Projects/Intermediate/) project.
