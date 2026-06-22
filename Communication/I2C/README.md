# I2C (Inter-Integrated Circuit)

A 2-wire protocol that lets multiple devices share the same two lines, each identified by a unique address. This is why I2C devices only need 4 wires total (power, ground, SDA, SCL) even when you have several connected at once.

## Key Concepts

- **SDA (Serial Data)** — the line data travels on, shared by all I2C devices
- **SCL (Serial Clock)** — the shared clock line that keeps all devices in sync (this is what makes I2C "synchronous," unlike UART)
- **Device address** — a 7-bit (occasionally 10-bit) address unique to each device on the bus, so the microcontroller knows which device it's talking to. Some modules let you change their address via solder jumpers if you need two of the same sensor on one bus.
- **Pull-up resistors** — SDA and SCL need pull-up resistors (often already built into breakout boards) to function correctly

## Common Modules Using I2C (in this repo)

| Module | Typical Address |
|---|---|
| SSD1306 OLED Display | `0x3C` or `0x78` |
| MPU6050 (Accelerometer + Gyroscope) | `0x68` (or `0x69` with AD0 pulled high) |
| BMP280 (Pressure + Temperature) | `0x76` or `0x77` |

## Wiring Pattern

```
Board SDA  →  Module SDA
Board SCL  →  Module SCL
Board 3.3V/5V → Module VCC (check module's voltage rating)
Board GND  →  Module GND
```

On most Arduino boards, SDA/SCL are fixed pins (Uno: A4/A5; Mega: 20/21). On ESP32/ESP8266 they're configurable in software but default to specific GPIOs — check your board's README.

## Finding a Device's Address

If you're not sure of a module's I2C address, run an **I2C scanner sketch** (search "Arduino I2C scanner" — a few lines of code that lists every address found on the bus). This is the fastest way to debug "device not responding" issues.

## Example Code

*(Will link to MPU6050, BMP280, and OLED examples once added — see [Roadmap.md](../../Roadmap.md).)*
