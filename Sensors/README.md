# Sensors

Sensor-by-sensor reference, grouped by category. Every sensor folder follows the same pattern so you always know what to expect.

## Folder Pattern (every sensor follows this)

```
Sensor-Name/
├── README.md          Description, connection table, working principle, formula, libraries, notes
└── Example_Code.ino    Tested-pattern Arduino sketch with inline wiring comments
```

*(Wiring is given as clear connection tables + ASCII diagrams inside each README; datasheet links are in each README header. Notes/calibration/gotchas are folded into the README so everything for a sensor is in one place.)*

> 📝 Sensor code is **reference code** written from manufacturer datasheets and standard libraries. It's marked as such because — unlike the microcontroller Blink tests — it hasn't been run on hardware here. Verify wiring for your specific module.

## Categories & Index

| Category | Sensors Documented | Difficulty |
|---|---|---|
| [Temperature](Temperature/) | LM35, DHT11, DHT22, DS18B20 | Beginner |
| [Distance](Distance/) | HC-SR04 | Beginner |
| [Motion](Motion/) | PIR (HC-SR501) | Beginner |
| [Light](Light/) | LDR | Beginner |
| [Gas](Gas/) | MQ-2 | Beginner |
| [IMU](IMU/) | MPU6050 | Intermediate |
| [Pressure](Pressure/) | BMP280 | Intermediate |
| [RFID](RFID/) | RC522 | Intermediate |
| [Display](Display/) | SSD1306 OLED | Intermediate |

**Looking for advanced/industrial parts?** ECG, pulse oximetry, 9-DOF IMUs, optical ToF, LIDAR, color sensors, current sensors, load cells, and more are cataloged in [Component-Reference](../Component-Reference/README.md).

## How to Use

1. Find your sensor's category above
2. Open the sensor's folder and read its README — connection table, voltage notes, working principle, and required libraries
3. Install any required libraries (see [Libraries-Reference](../Libraries-Reference/README.md))
4. Wire it up using the connection table, then upload `Example_Code.ino`

See [Roadmap.md](../Roadmap.md) for the recommended learning order through these sensors.
