/*
  DHT22 (AM2302) - Temperature & Humidity
  ---------------------------------------
  Reads temperature (C) and humidity (%) over the DHT single-wire protocol.

  Libraries required (install via Library Manager):
    - "DHT sensor library" by Adafruit
    - "Adafruit Unified Sensor" by Adafruit (dependency)

  Wiring (Arduino Uno/Nano/Mega):
    DHT22 VCC  -> 5V (3.3-6V ok; 3.3V on ESP32/ESP8266)
    DHT22 DATA -> D2  (add a 10k pull-up resistor between DATA and VCC)
    DHT22 GND  -> GND

  NOTE: This is reference code. Verify the pin and pull-up for your module.
  The DHT22 needs a ~2 second interval between reads.
*/

#include "DHT.h"

#define DHTPIN 2        // Digital pin connected to DATA
#define DHTTYPE DHT22   // DHT22 (AM2302). Use DHT11 for the DHT11.

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  Serial.println(F("DHT22 test"));
  dht.begin();
}

void loop() {
  delay(2000); // DHT22 needs ~2s between reads

  float humidity = dht.readHumidity();
  float tempC = dht.readTemperature();        // Celsius
  // float tempF = dht.readTemperature(true); // Fahrenheit

  if (isnan(humidity) || isnan(tempC)) {
    Serial.println(F("Failed to read from DHT sensor - check wiring/pull-up."));
    return;
  }

  Serial.print(F("Humidity: "));
  Serial.print(humidity);
  Serial.print(F(" %   Temperature: "));
  Serial.print(tempC);
  Serial.println(F(" C"));
}
