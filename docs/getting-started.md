# Getting Started

This guide gets you from "nothing installed" to "ready to upload code" — covering the Arduino IDE, driver setup, and board manager configuration for ESP32/ESP8266.

---

## 1. Download & Install Arduino IDE

Download the latest **Arduino IDE 2.x** for your OS from the official site:

👉 **https://www.arduino.cc/en/software**

| OS | Notes |
|---|---|
| Windows | Run the installer `.exe` and follow the prompts |
| macOS | Drag the app into your Applications folder |
| Linux | Extract the archive, then run the `arduino-ide` file (you may need to run it from a terminal the first time: `./arduino-ide`) |

> Use **Arduino IDE 2.x**, not the legacy 1.8.x version. It has a better board manager, built-in serial monitor/plotter, and autocomplete. Some screenshots in older tutorials online still show 1.8.x — the steps below match 2.x.

---

## 2. Install USB Drivers

Most Arduino boards (Uno, Nano, Mega) are recognized automatically on Windows 10/11 and macOS/Linux with no extra driver. ESP32/ESP8266 dev boards usually need one of these, depending on the onboard USB-to-serial chip:

| Chip | Used on | Driver |
|---|---|---|
| CH340/CH341 | Many cheap NodeMCU/ESP32 boards | [CH340 driver](http://www.wch.cn/download/CH341SER_ZIP.html) |
| CP2102/CP210x | Many ESP32 DevKits, some NodeMCU | [CP210x driver](https://www.silabs.com/developers/usb-to-uart-bridge-vcp-drivers) |

If your board doesn't show up under **Tools → Port** after plugging it in, this is almost always the cause — see [troubleshooting.md](troubleshooting.md).

---

## 3. Add ESP32 & ESP8266 Board Support

Arduino Uno/Nano/Mega work out of the box. ESP32 and ESP8266 need their board packages added manually:

1. Open **File → Preferences** (Windows/Linux) or **Arduino IDE → Settings** (macOS)
2. Find **"Additional Boards Manager URLs"** and paste both URLs, comma-separated:
   ```
   https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json, http://arduino.esp8266.com/stable/package_esp8266com_index.json
   ```
3. Click **OK**
4. Go to **Tools → Board → Boards Manager**
5. Search **"esp32"** → install **"esp32 by Espressif Systems"**
6. Search **"esp8266"** → install **"esp8266 by ESP8266 Community"**

This can take a few minutes — it's downloading the full toolchain, not just a small package.

---

## 4. Select Your Board & Port

Every time you switch boards:

1. **Tools → Board** → pick your exact board (e.g. "Arduino Uno", "ESP32 Dev Module", "NodeMCU 1.0 (ESP-12E Module)")
2. **Tools → Port** → select the COM port (Windows) or `/dev/tty.*` (Mac/Linux) that appeared when you plugged in the board
3. For ESP32/ESP8266, also check **Tools → Upload Speed** — default `115200` is safest; `921600` is faster once you know your setup is stable

---

## 5. Run Your First Test

Go to [`Microcontrollers/`](../Microcontrollers/), open the folder matching your board, and upload the **Blink LED** sketch inside its `Examples/` folder. If the onboard LED blinks, your IDE + drivers + board selection are all correct — you're ready to move on to sensors.

---

## Next Steps

- [Library installation guide](library-installation-guide.md) — how to install the libraries used throughout this repo
- [Troubleshooting](troubleshooting.md) — fixes for common upload/connection errors
