# SSD1306 — 128×64 OLED Display (I²C)

> 📝 **Reference code** — verify wiring for your specific module before relying on it.

📄 **Datasheet:** [SSD1306 (Adafruit mirror)](https://cdn-shop.adafruit.com/datasheets/SSD1306.pdf)

## Description

The SSD1306 is a small, crisp monochrome OLED — the standard way to give a sensor project a display without a backlight or bulky LCD. Most are 128×64 (some 128×32) and connect over I²C with just two signal wires. Ideal for showing live sensor readings.

| Parameter | Value |
|---|---|
| Resolution | 128×64 (or 128×32) |
| Controller | SSD1306 |
| Interface | I²C (address 0x3C, sometimes 0x3D) — also SPI variants exist |
| Colors | Monochrome (white/blue/yellow per panel) |
| Operating voltage | 3.3 V or 5 V (most modules accept both) |

## Connection (I²C)

| OLED Pin | Uno/Nano | Mega | ESP32 |
|---|---|---|---|
| VCC | 3.3V or 5V | same | 3.3V |
| GND | GND | GND | GND |
| SCL | A5 | 21 | GPIO22 |
| SDA | A4 | 20 | GPIO21 |

## Working Principle

Each pixel is an individual organic LED that emits its own light — so OLEDs need no backlight and have high contrast. The SSD1306 controller holds a frame buffer; the Arduino writes pixels/text into the Adafruit GFX buffer, then `display()` pushes the buffer to the screen over I²C.

## Libraries

| Library (search exactly) | Author | Purpose |
|---|---|---|
| Adafruit SSD1306 | Adafruit | Display driver |
| Adafruit GFX Library | Adafruit | Graphics/text primitives |
| Adafruit BusIO | Adafruit | Dependency |

## Example Code

See [`Example_Code.ino`](Example_Code.ino) — prints text in two sizes as a display test.

## Notes & Gotchas

- Most modules are I²C address **0x3C**; a few are **0x3D**. If the screen stays black, run an I²C scanner to confirm.
- `SSD1306 allocation failed` usually means the wrong address or a wiring fault.
- Remember to call **`display.display()`** — drawing to the buffer shows nothing until you push it.
- This is the **OLED SSD1306** from your roadmap's first-10 list, and the display for the [Smart Weather Station](../../../Projects/Intermediate/) project.
