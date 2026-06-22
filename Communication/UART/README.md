# UART (Universal Asynchronous Receiver/Transmitter)

The simplest serial protocol — just two wires, no shared clock line. Used for the Arduino Serial Monitor, GPS modules, Bluetooth modules (HC-05/HC-06), and most simple point-to-point communication.

## Key Concepts

- **TX (Transmit) / RX (Receive)** — TX on one device connects to RX on the other, and vice versa (cross them, don't connect TX-to-TX)
- **Baud rate** — the agreed-upon speed (bits per second) both devices must match exactly. Common values: `9600`, `115200`. Mismatched baud rate is the #1 cause of garbled Serial Monitor output.
- **No clock line** — both sides must already agree on timing (the baud rate) since there's no shared clock signal like in SPI/I2C — hence "asynchronous"

## Where You've Already Used It

If you've used `Serial.begin(9600)` and `Serial.println(...)` in any sketch so far, you've been using UART the whole time — between your board and your computer over USB.

## Common Modules Using UART

| Module | Notes |
|---|---|
| HC-05 / HC-06 Bluetooth | Classic Bluetooth serial bridge |
| NEO-6M GPS | Outputs NMEA sentences over UART |
| SIM800L GSM | AT-command based, UART |

## Wiring Pattern

```
Board TX  →  Module RX
Board RX  ←  Module TX
Board GND →  Module GND
```

> ⚠️ Many UART modules (GPS, Bluetooth, GSM) run on 3.3V logic. If using a 5V board (Uno/Nano/Mega), check the module's voltage requirements — a logic-level converter or simple voltage divider on the TX line may be needed to protect the module.

## Example Code

*(Coming soon — will link to a GPS or Bluetooth module example once added to the repo.)*
