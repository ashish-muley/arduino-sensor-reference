# Troubleshooting

Common issues you'll hit while working through this repo, and how to fix them.

---

## Board not detected / no COM port shows up

- Install the correct USB driver for your board's chip — see [getting-started.md](getting-started.md#2-install-usb-drivers)
- Try a different USB cable. Many cheap cables are "charge-only" and carry no data lines.
- On Windows, check **Device Manager** for a device with a yellow warning icon under "Ports" or "Other devices"
- Unplug, wait 5 seconds, replug. Sounds silly, fixes it surprisingly often.

## Upload fails / times out

- Make sure no other program (Serial Monitor, another IDE instance) has the port open
- For ESP32/ESP8266 boards without auto-reset: hold the **BOOT**/**FLASH** button while upload starts, release once it begins writing
- Try a lower **Tools → Upload Speed** (e.g. drop from 921600 to 115200)
- Confirm **Tools → Board** matches your actual board exactly — wrong board = wrong bootloader assumptions

## `espcomm_sync failed` / `Failed to connect to ESP32/ESP8266`

- This is almost always a boot-mode issue. On boards without auto-reset circuitry, hold BOOT, click Upload in the IDE, wait until you see "Connecting...", then release BOOT
- Double check you selected the right **Port**, not just the right board

## `fatal error: <library>.h: No such file or directory`

- The library isn't installed, or installed under a different name. Re-check the exact library name in the sensor's README and reinstall via Library Manager — see [library-installation-guide.md](library-installation-guide.md)
- If you have two libraries with conflicting names (common with display/sensor libraries), remove the one you're not using from `Documents/Arduino/libraries/`

## Sensor returns 0, NaN, or garbage values

- Double-check wiring against the sensor's README — reversed VCC/GND is the #1 cause of "no response" or junk readings
- Some sensors (DHT11/22, ultrasonic) need a brief delay after power-up before their first reading is reliable
- Confirm voltage compatibility: many sensors are 5V-only or 3.3V-only. Running a 5V sensor's output directly into an ESP32 (3.3V logic) can damage the GPIO pin — check the sensor's datasheet folder

## ESP32/ESP8266 boards not showing in Tools → Board

- Confirm the board manager URLs were added correctly under **File → Preferences → Additional Boards Manager URLs** — see [getting-started.md](getting-started.md#3-add-esp32--esp8266-board-support)
- Restart the IDE after installing board packages
- If install fails outright, delete the `Arduino15` (Windows: `%LOCALAPPDATA%\Arduino15`) cache folder and retry — corrupted package index is a known recurring issue

---

Still stuck? Open an [issue](../../../issues) with your board, OS, IDE version, and the exact error message.
