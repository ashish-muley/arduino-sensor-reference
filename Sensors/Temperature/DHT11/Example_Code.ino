/*
  DHT11 - Temperature & Humidity
  ------------------------------
  Cheaper, lower-precision sibling of the DHT22. Same library and wiring,
  only the sensor type differs (DHT11 instead of DHT22).

  Libraries required (install via Library Manager):
    - "DHT sensor library" by Adafruit
    - "Adafruit Unified Sensor" by Adafruit (dependency)

  Wiring (Arduino Uno/Nano/Mega):
    DHT11 VCC  -> 5V (3.3-5.5V ok; 3.3V on ESP32/ESP8266)
    DHT11 DATA -> D2  (10k pull-up resistor between DATA and VCC; many
                       DHT11 breakout boards already include this resistor)
    DHT11 GND  -> GND

  NOTE: Reference code. DHT11 needs ~1 second between reads. Range is
  0-50 C (+/-2 C) and 20-90% RH (+/-5%) - less accurate than DHT22.
*/

#include "DHT.h"

#define DHTPIN 2
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  Serial.println(F("DHT11 test"));
  dht.begin();
}

void loop() {
  delay(1500); // DHT11 needs ~1s between reads

  float humidity = dht.readHumidity();
  float tempC = dht.readTemperature();

  if (isnan(humidity) || isnan(tempC)) {
    Serial.println(F("Failed to read from DHT sensor - check wiring."));
    return;
  }

  Serial.print(F("Humidity: "));
  Serial.print(humidity);
  Serial.print(F(" %   Temperature: "));
  Serial.print(tempC);
  Serial.println(F(" C"));
}
