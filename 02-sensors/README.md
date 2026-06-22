# Sensors

Sensor-by-sensor reference. Each sensor has its own folder containing wiring instructions, datasheet, required libraries, and tested code for one or more boards.

## Index

| Sensor | Type | Tested Boards | Folder |
|---|---|---|---|
| *(none yet — first sensor coming soon)* | | | |

This table is updated every time a new sensor folder is added.

## Folder Structure (per sensor)

```
sensor-name/
├── README.md          Wiring diagram, pin connections, voltage notes, library list
├── datasheet/          Sensor datasheet PDF and key specs summary
├── arduino-uno/         (or whichever board) tested .ino sketch
└── esp32/                another board's tested .ino sketch
```

## How to Use

1. Find your sensor in the table above
2. Open its folder and read the README — it lists exactly which pins connect where, and any voltage-compatibility warnings for your board
3. Install the libraries listed (see [library installation guide](../docs/library-installation-guide.md) if needed)
4. Open the `.ino` file for your specific board and upload it

Don't see your sensor yet? Check back — new sensors are added regularly. Want to contribute one yourself? See the main [README](../README.md#-contributing).
