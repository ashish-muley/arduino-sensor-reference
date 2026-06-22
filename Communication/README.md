# Communication Protocols

Understanding these is what separates "I copied a sketch" from "I understand how the sensor actually talks to the microcontroller." Every protocol folder explains the wiring convention, key terms, and links to sensors/modules in this repo that use it.

## Index

| Protocol | Used By (in this repo) | Key Concepts |
|---|---|---|
| [UART](UART/) | Serial Monitor, GPS modules, Bluetooth modules | TX/RX, baud rate |
| [I2C](I2C/) | OLED (SSD1306), MPU6050, BMP280 | SDA, SCL, device address |
| [SPI](SPI/) | SD cards, TFT displays, RC522 RFID, NRF24L01 | MOSI, MISO, SCK, CS |
| [CAN](CAN/) | Automotive/industrial modules *(planned)* | CAN-H, CAN-L, arbitration |

## Why This Section Exists

Most sensor tutorials online skip explaining *why* a sensor needs 2 wires (I2C) vs 4 wires (SPI) vs a simple TX/RX pair (UART). This section exists so that by the time you're wiring your 3rd or 4th sensor, you're recognizing the pattern instead of just copy-pasting pin numbers.

See [Roadmap.md](../Roadmap.md) — Stage 3 covers these in the recommended learning order, right after the first batch of basic sensors.
