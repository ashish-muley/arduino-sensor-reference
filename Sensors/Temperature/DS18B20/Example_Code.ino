/*
  DS18B20 - 1-Wire Digital Temperature Sensor
  -------------------------------------------
  Digital sensor on the Dallas 1-Wire bus. Each sensor has a unique ID,
  so multiple DS18B20s can share a single data pin.

  Libraries required (install via Library Manager):
    - "OneWire" by Paul Stoffregen
    - "DallasTemperature" by Miles Burton

  Wiring (Arduino Uno/Nano/Mega):
    DS18B20 VCC  -> 5V (3.0-5.5V)
    DS18B20 DATA -> D2  (REQUIRED: 4.7k pull-up resistor between DATA and VCC)
    DS18B20 GND  -> GND
    (Waterproof probe version: red=VCC, yellow/blue=DATA, black=GND)

  NOTE: Reference code. The 4.7k pull-up on the data line is mandatory -
  the bus will not work without it.
*/

#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS 2  // Data pin

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

void setup() {
  Serial.begin(9600);
  Serial.println("DS18B20 test");
  sensors.begin();
}

void loop() {
  sensors.requestTemperatures();          // Ask all sensors on the bus
  float tempC = sensors.getTempCByIndex(0); // First sensor

  if (tempC == DEVICE_DISCONNECTED_C) {
    Serial.println("Error: DS18B20 not found - check wiring/pull-up.");
  } else {
    Serial.print("Temperature: ");
    Serial.print(tempC);
    Serial.println(" C");
  }

  delay(1000);
}
