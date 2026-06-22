# RC522 (MFRC522) — 13.56 MHz RFID Reader (SPI)

> 📝 **Reference code** — verify wiring for your specific module before relying on it.

📄 **Datasheet:** [MFRC522 (NXP)](https://www.nxp.com/docs/en/data-sheet/MFRC522.pdf)

## Description

The RC522 is a contactless RFID reader/writer built on NXP's MFRC522 IC, operating at 13.56 MHz. It reads ISO/IEC 14443A / MIFARE cards and key fobs over SPI — the classic module for access control, attendance systems, and "tap to unlock" projects. Also a great way to learn the SPI bus.

| Parameter | Value |
|---|---|
| Frequency | 13.56 MHz |
| Card types | ISO/IEC 14443A, MIFARE Classic 1K/4K, NTAG |
| Read range | up to ~50 mm |
| Interface | SPI (also supports I²C/UART, but library uses SPI) |
| Operating voltage | **3.3 V only** |

## Connection (SPI)

| RC522 Pin | Uno/Nano | Mega | Notes |
|---|---|---|---|
| SDA (SS) | D10 | configurable | Chip-select; labeled `SS` on some boards |
| SCK | D13 | 52 | SPI clock |
| MOSI | D11 | 51 | |
| MISO | D12 | 50 | |
| RST | D9 | configurable | Reset |
| 3.3V | 3.3V | 3.3V | **Never 5 V — it can damage the module** |
| GND | GND | GND | |

```
  SDA(SS) → D10        RST  → D9
  SCK     → D13        3.3V → 3.3V  (NOT 5V!)
  MOSI    → D11        GND  → GND
  MISO    → D12
```

## Working Principle

The reader generates a 13.56 MHz field that powers a nearby passive card and exchanges data with it. Each card carries a unique ID (UID); the MFRC522 handles ISO 14443A framing, anti-collision, and (for MIFARE) Crypto1 authentication. The Arduino talks to the reader over SPI and pulls the UID — the simplest, most common operation.

## Libraries

| Library (search exactly) | Author | Purpose |
|---|---|---|
| MFRC522 | GithubCommunity (miguelbalboa) | Reader driver |

> The original `miguelbalboa/rfid` library is in "freeze" (stable, maintenance-only) — still the standard. For active development there's a `MFRC522v2` successor.

## Example Code

See [`Example_Code.ino`](Example_Code.ino) — prints each scanned card's UID in hex.

## Notes & Gotchas

- **3.3 V power only.** This is the most common way people fry the module.
- `Firmware Version: 0x00` or "Communication failure" → almost always a wiring/SPI issue; re-check SS, RST, and the SPI pins.
- The card **UID is not secure** — cheap "magic" cards can be cloned. Don't rely on UID alone for real security; use sector authentication for anything serious.
- To find a card's UID, the library's `DumpInfo` example (File → Examples → MFRC522) prints everything.
- Used in the [RFID Attendance System](../../../Projects/Intermediate/) project.
