# DHT22 (AM2302) — Temperature & Humidity

> 📝 **Reference code** — written from manufacturer docs and standard libraries; verify wiring for your specific module before relying on it.

📄 **Datasheet:** [DHT22 (SparkFun mirror)](https://cdn.sparkfun.com/assets/f/7/d/9/c/DHT22.pdf) · [AM2302 (Adafruit)](https://cdn-shop.adafruit.com/datasheets/Digital+humidity+and+temperature+sensor+AM2302.pdf)

## Description

The DHT22 (also sold as AM2302) is a low-cost digital temperature and humidity sensor. It combines a polymer humidity capacitor and a thermistor with a small onboard microcontroller that outputs calibrated readings over a single-wire protocol — so no analog calibration is needed on your side.

| Parameter | Value |
|---|---|
| Temperature range | −40 °C to 80 °C (±0.5 °C) |
| Humidity range | 0–100% RH (±2%) |
| Operating voltage | 3.3 V – 6 V |
| Output | Digital, proprietary single-wire (1-wire-style) |
| Minimum read interval | ~2 seconds |
| Data payload | 40 bits (16 RH + 16 Temp + 8 checksum) |

## Connection

| DHT22 Pin | Connects To | Notes |
|---|---|---|
| VCC (Pin 1) | 5V (or 3.3V on ESP32/ESP8266) | |
| DATA (Pin 2) | D2 | **Add a 10 kΩ pull-up** between DATA and VCC |
| Pin 3 | — | Not connected |
| GND (Pin 4) | GND | |

```
   DHT22
  ┌───────┐
  │ ▢ ▢ ▢ ▢│
  └─┬─┬───┬─┘
    │ │   └── GND  → GND
    │ └────── DATA → D2  (+ 10kΩ to VCC)
    └──────── VCC  → 5V
   (Pin 3 unused)
```

## Working Principle

The humidity capacitor's dielectric changes capacitance with moisture; the thermistor changes resistance with temperature. The onboard MCU samples both, applies factory calibration, and clocks out a 40-bit digital frame. The host (Arduino) reads that frame via the DHT library — you never touch the raw analog signal.

## Libraries

| Library (search exactly) | Author | Purpose |
|---|---|---|
| DHT sensor library | Adafruit | Core driver |
| Adafruit Unified Sensor | Adafruit | Dependency |

Install both via **Sketch → Include Library → Manage Libraries**.

## Example Code

See [`Example_Code.ino`](Example_Code.ino) — prints temperature (°C) and humidity (%) every 2 seconds.

## Notes & Gotchas

- The **2-second minimum interval** is real — read faster and you'll get stale values or `nan`.
- A missing pull-up resistor is the most common cause of `Failed to read from DHT sensor`. Many breakout-board versions include the pull-up already; the bare 4-pin sensor does not.
- On 3.3 V boards (ESP32/ESP8266) power from 3.3 V — the data line follows VCC, so a 5 V-powered sensor would drive 5 V into a 3.3 V GPIO.
- For higher accuracy or a true I²C interface, the Sensirion **SHT31-D** is a step up (±0.3 °C, selectable address 0x44/0x45) — documented in [Component-Reference](../../../Component-Reference/README.md).
