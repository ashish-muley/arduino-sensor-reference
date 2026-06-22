/*
  BMP280 - Barometric Pressure + Temperature (I2C)
  ------------------------------------------------
  Measures atmospheric pressure (300-1100 hPa) and temperature, and can
  estimate altitude. I2C address is 0x76 on most breakouts (some use 0x77).

  *** BMP280 vs BME280: the BMP280 does NOT measure humidity. If your board
      reports humidity too, it is a BME280 - use the Adafruit BME280 library
      instead. ***

  Libraries required (install via Library Manager):
    - "Adafruit BMP280 Library" by Adafruit
    - "Adafruit Unified Sensor" by Adafruit (dependency)
    - "Adafruit BusIO" by Adafruit (dependency)

  Wiring (Arduino Uno/Nano - I2C):
    BMP280 VCC -> 3.3V (or 5V if the board has a regulator) 
    BMP280 GND -> GND
    BMP280 SCL -> A5 (Uno/Nano) | 21 (Mega) | GPIO22 (ESP32)
    BMP280 SDA -> A4 (Uno/Nano) | 20 (Mega) | GPIO21 (ESP32)

  NOTE: Reference code. For accurate altitude, replace 1013.25 with the
  current local sea-level pressure (hPa) from a weather service.
*/

#include <Wire.h>
#include <Adafruit_BMP280.h>

Adafruit_BMP280 bmp; // I2C

void setup() {
  Serial.begin(9600);
  while (!Serial) delay(10);

  if (!bmp.begin(0x76)) {           // try 0x77 if this fails
    Serial.println("BMP280 not found at 0x76 - try 0x77 or check wiring.");
    while (1) delay(10);
  }
  Serial.println("BMP280 ready");
}

void loop() {
  Serial.print("Temperature: ");
  Serial.print(bmp.readTemperature());
  Serial.println(" C");

  Serial.print("Pressure: ");
  Serial.print(bmp.readPressure() / 100.0F); // Pa -> hPa
  Serial.println(" hPa");

  Serial.print("Approx altitude: ");
  Serial.print(bmp.readAltitude(1013.25));   // local sea-level hPa
  Serial.println(" m");

  Serial.println();
  delay(1000);
}
