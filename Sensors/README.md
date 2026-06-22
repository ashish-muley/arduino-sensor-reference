# Sensors

Sensor-by-sensor reference, grouped by category. Every sensor folder follows the same pattern so you always know what to expect.

## Folder Pattern (every sensor follows this)

```
Sensor-Name/
├── README.md          Description, pinout, working principle, formulas, example usage
├── Wiring.png          Wiring/breadboard diagram
├── Example_Code.ino    Tested working sketch
├── Datasheet.pdf        Official datasheet (sourced from the manufacturer — see Datasheets/README.md)
└── Notes.md             Calibration tips, gotchas, common mistakes
```

## Categories & Index

| Category | Sensors | Difficulty |
|---|---|---|
| [Temperature](Temperature/) | DHT11, LM35 | Beginner |
| [Distance](Distance/) | HC-SR04 | Beginner |
| [Motion](Motion/) | PIR | Beginner |
| [Light](Light/) | LDR | Beginner |
| [Gas](Gas/) | MQ-2 | Beginner |
| [IMU](IMU/) | MPU6050 | Intermediate |
| [Pressure](Pressure/) | BMP280 | Intermediate |
| [RFID](RFID/) | RC522 | Intermediate |
| [Display](Display/) | SSD1306 OLED | Intermediate |

*(Empty category folders are placeholders — populated as sensors are added. See [Roadmap.md](../Roadmap.md) for the planned learning order.)*

## How to Use

1. Find your sensor's category above
2. Open the sensor's folder and read its README — wiring, voltage notes, working principle, and required libraries
3. Install any required libraries (see [Libraries-Reference](../Libraries-Reference/README.md))
4. Wire it up using `Wiring.png`, then upload `Example_Code.ino`

Don't see your sensor yet? Check [Roadmap.md](../Roadmap.md) for what's planned next, or open an [issue](../../../issues) to request it.
