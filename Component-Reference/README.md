# Component Reference

A categorized catalog of **advanced, specialized, and industrial** sensors, modules, and compute platforms — drawn from in-depth datasheet research. This is a *reference* section: it documents real specifications, operating principles, and official datasheet links so the repo is genuinely useful beyond the beginner sensors in [`../Sensors/`](../Sensors/).

> **Why these are separate from `Sensors/`:** The components below range from accessible-but-advanced (extra libraries, more theory) to industrial-grade parts that don't use simple Arduino sketches at all (4–20 mA current loops, safety-rated scanners, proprietary interfaces). Rather than publish fabricated "Arduino example code" for hardware that doesn't work that way, each entry gives accurate specs and a datasheet link. Entries marked **🟢 Arduino-friendly** have well-supported libraries and can graduate to a full folder in `Sensors/` over time.

---

## Biometric & Physiological Sensors

| Module | Measures | Output | Voltage | Interface | Datasheet |
|---|---|---|---|---|---|
| **AD8232** 🟢 | ECG / cardiac biopotential | Analog | 2.0–3.5 V | Analog out | [Analog Devices](https://www.analog.com/media/en/technical-documentation/data-sheets/ad8232.pdf) |
| **MAX30102** 🟢 | PPG / pulse oximetry (HR, SpO₂) | Digital | 1.8 V logic / 3.3 V LEDs | I²C | [Analog Devices](https://www.analog.com/media/en/technical-documentation/data-sheets/max30102.pdf) |
| **MyoWare 2.0** 🟢 | EMG / muscle activation | Analog (Raw/Rectified/Envelope) | 2.27–5.47 V | Analog out | [SparkFun](https://www.sparkfun.com/myoware) |

**AD8232 (ECG):** A single-lead ECG analog front-end. Its job is rejecting huge common-mode interference (especially 50/60 Hz mains) to recover tiny heart signals — it reaches 80 dB CMRR using an instrumentation amp plus a Right-Leg-Drive that actively cancels common-mode voltage. Outputs an analog waveform you read on an ADC pin.

**MAX30102 (Pulse Oximetry):** A reflective optical sensor with red (660 nm) + infrared (880 nm) LEDs and an 18-bit ADC. Heart rate and SpO₂ come from the differential light absorption of oxygenated vs deoxygenated hemoglobin. Talks I²C, has a 32-sample FIFO to reduce host polling.

**MyoWare 2.0 (EMG):** Measures muscle electrical activity. Offers Raw, Rectified, and Envelope analog outputs (the Envelope is the smoothed "how hard is the muscle flexing" signal most projects use). 140 dB CMRR isolates the muscle signal from environmental noise.

---

## Environmental, Gas & Atmospheric

| Module | Measures | Range | Interface | Datasheet |
|---|---|---|---|---|
| **SHT31-D** 🟢 | Temp + humidity (high precision) | −40…125 °C, 0–100% RH | I²C (0x44/0x45) | [Sensirion](https://sensirion.com/products/catalog/SHT31-DIS-B) |
| **SCD41** 🟢 | CO₂ (true NDIR) | 400–5000 ppm | I²C | [Sensirion](https://sensirion.com/media/documents/48C4B7FB/67FE0194/CD_DS_SCD4x_Datasheet_D1.pdf) |
| **BME680** 🟢 | Temp + humidity + pressure + VOC gas | — | I²C/SPI | [Bosch](https://www.bosch-sensortec.com/products/environmental-sensors/gas-sensors/bme680/) |

**SHT31-D:** A precision upgrade over the DHT22 — ±0.3 °C / ±2% RH on a true I²C bus with selectable address and a built-in heater to clear condensation. The right choice when accuracy matters.

**SCD41:** A real CO₂ sensor using photoacoustic NDIR (modulated IR excites CO₂ molecules; a MEMS microphone detects the resulting pressure waves). Far more accurate for actual CO₂ than an MQ-series sensor, with onboard temp/humidity compensation. Ideal for air-quality monitors.

---

## Inertial, Spatial & Motion

| Module | DOF | Key Feature | Interface | Datasheet |
|---|---|---|---|---|
| **ADXL345** 🟢 | 3 (accel) | 13-bit, tap/free-fall detection | I²C/SPI | [Analog Devices](https://www.analog.com/media/en/technical-documentation/data-sheets/adxl345.pdf) |
| **BNO055** 🟢 | 9 (absolute orientation) | Onboard fusion → Euler/Quaternion | I²C/UART | [Bosch](https://www.bosch-sensortec.com/media/boschsensortec/downloads/datasheets/bst-bno055-ds000.pdf) |
| **ADXL335** 🟢 | 3 (accel, analog) | ±3 g analog output | Analog | — |

**ADXL345:** A dedicated 3-axis accelerometer with 13-bit resolution and embedded tap/double-tap/free-fall detection — great for vibration monitoring and shock logging. Very low power (~23 µA).

**BNO055:** The "easy mode" IMU — it integrates accel + gyro + magnetometer **and** a Cortex-M0+ running Bosch's fusion software, outputting absolute orientation (Euler angles / quaternions) directly. No complementary/Kalman filter to write yourself. ⚠️ Uses I²C clock-stretching, which trips up some rigid I²C controllers (notably older ESP32 ESP-IDF) — may need a workaround.

---

## Distance, Ranging & Optical Topography

| Module | Tech | Range | Interface | Datasheet |
|---|---|---|---|---|
| **VL53L1X** 🟢 | Optical ToF (laser) | up to 4 m | I²C | [STMicroelectronics](https://www.st.com/resource/en/datasheet/vl53l1x.pdf) |
| **VL53L0X** 🟢 | Optical ToF (laser) | up to ~2 m | I²C | [ST](https://www.st.com/resource/en/datasheet/vl53l0x.pdf) |
| **GP2Y0A21** 🟢 | Sharp IR analog | 10–80 cm | Analog | — |
| **RPLIDAR A1** | 2D spinning LIDAR | 0.15–12 m | UART | [Slamtec](https://www.slamtec.com/en/lidar/a1) |
| **SICK microScan3** | Safety laser scanner | up to 9 m | EtherNet/IP, PROFINET, EtherCAT | [SICK](https://www.sick.com/media/pdf/5/45/545/dataSheet_microScan3-safety-laser-scanne_1611301_en.pdf) |

**VL53L1X / VL53L0X (ToF):** Measure the actual time light takes to travel to a target and back, so readings are largely **independent of target color/reflectance** — a big advantage over ultrasonic or simple IR. The VL53L1X reaches 4 m and supports programmable region-of-interest. The natural upgrade from the HC-SR04.

**RPLIDAR A1:** A spinning 2D laser scanner producing 360° point clouds (8000 samples/s, up to 12 m) for SLAM/mapping robots. Interfaces over UART with a host that runs the SDK — beyond a simple `analogRead`, but very approachable on a Raspberry Pi or capable MCU.

**SICK microScan3 (industrial, not Arduino):** A *safety-rated* laser scanner that protects people around machinery (PL d / SIL 2). Uses multi-pulse ToF to ignore dust and ambient light, supports up to 128 configurable safety fields, and speaks industrial safety buses (CIP Safety, PROFIsafe, FSoE) to a PLC — **not** a hobby Arduino interface. Included here for completeness as a professional reference.

---

## Industrial Optics, Color & RFID

| Module | Function | Interface | Datasheet |
|---|---|---|---|
| **TCS34725** 🟢 | RGB color sensor (with IR filter) | I²C | [Adafruit/AMS](https://cdn-shop.adafruit.com/datasheets/TCS34725.pdf) |
| **TCS3200** 🟢 | Color sensor (frequency output) | Digital (freq) | — |
| **TCRT5000** 🟢 | Reflective IR proximity / line sensor | Analog/Digital | [Vishay](https://www.vishay.com/docs/83760/tcrt5000.pdf) |
| **TSOP17xx** 🟢 | 38 kHz IR remote receiver | Digital | — |
| **Keyence FS-N40** | Industrial fiber-optic amplifier | Industrial I/O | [Keyence](https://www.keyence.com/products/sensor/fiber-optic/fs-n40/) |

**TCS34725 (Color):** An accurate RGB-to-digital color sensor with an on-chip IR-blocking filter (unfiltered IR badly skews color reads). Programmable gain and integration time over I²C — used for color sorting and matching.

**TCRT5000 (Reflective IR):** A cheap IR emitter + phototransistor pair for line-following robots and edge/object detection at a few millimeters, with a daylight filter to reject ambient light.

---

## Mechanical, Force & Acoustic

| Module | Measures | Interface | Datasheet |
|---|---|---|---|
| **FSR402** 🟢 | Force (single zone) | Analog (via divider) | [SparkFun](https://cdn.sparkfun.com/assets/8/a/1/2/0/2010-10-26-DataSheet-FSR402-Layout2.pdf) |
| **HX711 + load cell** 🟢 | Weight (strain gauge ADC) | Digital (2-wire) | [HX711](https://www.digikey.com/htmldatasheets/production/1836471/0/0/1/hx711.html) |
| **PEC11R / KY-040** 🟢 | Rotary encoder (position/direction) | Digital quadrature | [Bourns](https://www.bourns.com/docs/Product-Datasheets/PEC11R.pdf) |
| **YF-S201** 🟢 | Water flow (Hall + turbine) | Digital pulse | — |
| **Mistras D9241A / PK15I** | Acoustic emission (structural NDT) | Analog (specialized) | [Physical Acoustics](https://www.physicalacoustics.com/) |
| **Danfoss MBS 3000** | Industrial pressure transmitter | 4–20 mA loop | [Danfoss](https://assets.danfoss.com/documents/latest/156946/AI308930736185en-000201.pdf) |

**FSR402 (Force):** Resistance drops as force is applied; read via a voltage divider. Non-linear (inverse power law), so it's good for relative force/touch sensing, not precise weight.

**HX711 + Load Cell (Weight):** A 24-bit ADC amplifier purpose-built for Wheatstone-bridge strain-gauge load cells — the standard way to build a digital scale on Arduino.

**Rotary Encoder (KY-040 / PEC11R):** Generates two-phase (quadrature) pulses; the phase relationship gives both rotation direction and speed. Needs debouncing. Teaches quadrature decoding.

**Danfoss MBS 3000 / Mistras AE (industrial, not Arduino):** A 4–20 mA industrial pressure transmitter and acoustic-emission sensors for predictive maintenance — process-control hardware read by PLCs/specialized instrumentation, not hobby microcontrollers. Reference entries.

---

## Magnetic, Electrical & Thermal

| Module | Measures | Interface | Datasheet |
|---|---|---|---|
| **ACS712** 🟢 | Current (Hall, isolated) | Analog | [Allegro](https://www.allegromicro.com/-/media/files/datasheets/acs712-datasheet.ashx) |
| **A3144** 🟢 | Hall switch (magnet present) | Digital | — |
| **DRV5053** 🟢 | Analog Hall (linear flux, polarity) | Analog | [TI](https://www.ti.com/lit/gpn/DRV5053) |
| **TEC1-12706** | Peltier thermoelectric cooler | Power (12 V/6 A) | [Thermonamic](https://www.thermonamic.com/TEC1-12706-English-%2020220521.pdf) |

**ACS712 (Current):** Measures AC/DC current via Hall effect with 2.1 kV galvanic isolation between the high-current path and your logic. Outputs an analog voltage centered at VCC/2 (e.g. 185 mV/A on the 5 A model). The standard hobby current sensor.

**TEC1-12706 (Peltier, power device):** Not a sensor — a solid-state heat pump. Pumps heat from one face to the other when driven (12 V, up to 6 A). ⚠️ The hot side **must** have a heatsink + fan; running it without dissipation destroys the internal solder joints in seconds. Used in cooling/temperature-control projects.

---

## Compute Cores & Microcontrollers

Beyond the boards in [`../Microcontrollers/`](../Microcontrollers/), these represent the wider spectrum from real-time MCUs to Linux SBCs:

| Board | Core | Clock | Niche | Reference |
|---|---|---|---|---|
| **STM32 Blue Pill** (F103C8T6) 🟢 | ARM Cortex-M3 | 72 MHz | Cheap 32-bit ARM | [ST](https://www.st.com/en/microcontrollers-microprocessors/stm32f103c8.html) |
| **Nucleo-F401RE** 🟢 | ARM Cortex-M4 | 84 MHz | Industrial ARM dev, onboard ST-LINK | [ST](https://www.st.com/en/evaluation-tools/nucleo-f401re.html) |
| **Teensy 4.1** 🟢 | ARM Cortex-M7 | 600 MHz | Fastest hobby MCU, real-time DSP/audio | [PJRC](https://www.pjrc.com/store/teensy41.html) |
| **Raspberry Pi Pico** (RP2040) 🟢 | Dual Cortex-M0+ | 133 MHz | PIO, dual-core, ultra-cheap | [Raspberry Pi](https://www.raspberrypi.com/products/raspberry-pi-pico/) |
| **Raspberry Pi 5** | Quad Cortex-A76 (Linux SBC) | 2.4 GHz | Vision, ML, full OS, PCIe | [Raspberry Pi](https://www.raspberrypi.com/products/raspberry-pi-5/) |

**When to move up from an Uno/ESP32:**
- Need hard real-time (motor control, audio DSP) → **Teensy 4.1** (Cortex-M7, tightly-coupled memory for jitter-free timing).
- Industrial ARM ecosystem / onboard debugger → **Nucleo-F401RE**.
- Computer vision, ML inference, full Linux, camera → **Raspberry Pi 5** (an SBC, not an MCU — runs an OS, exposes PCIe for NVMe/NPU accelerators).
- Cheap dual-core MCU with programmable I/O → **Pico (RP2040)**.

---

## Display Modules

| Module | Tech | Interface | Reference |
|---|---|---|---|
| **SSD1306 OLED** 🟢 | OLED | I²C/SPI | [→ full folder](../Sensors/Display/SSD1306-OLED/) |
| **Waveshare e-Paper** 🟢 | E-Ink (bistable) | SPI | [Waveshare Wiki](https://www.waveshare.com/wiki/Main_Page#Display-e-Paper) |

**e-Paper (E-Ink):** Bistable electrophoretic displays that draw power **only during refresh** (~0.01 µA standby) and keep their image with power fully removed — ideal for battery devices and signage. Refresh is slow (2–4 s) and partial-refresh modes need periodic full refreshes to clear ghosting. Driven over SPI with 3.3 V logic.

---

## Wireless / IoT Modules

| Module | Tech | Interface | Notes |
|---|---|---|---|
| **ESP32 / ESP8266** 🟢 | Wi-Fi (+BT on ESP32) | — | See [`../Microcontrollers/`](../Microcontrollers/) — these are MCUs *with* Wi-Fi |
| **nRF24L01+** 🟢 | 2.4 GHz RF transceiver | SPI | Cheap board-to-board radio |
| **HC-05 / HC-06** 🟢 | Bluetooth Classic (serial) | UART | Wireless serial bridge |
| **SX127x (LoRa)** 🟢 | LoRa long-range | SPI | km-range low-bandwidth telemetry |

---

*This catalog is built from datasheet research and will keep growing. As Arduino-friendly (🟢) parts get tested wiring + code, they graduate into full folders under [`../Sensors/`](../Sensors/). For the official manufacturer datasheet portals, see [`../Datasheets/README.md`](../Datasheets/README.md).*
