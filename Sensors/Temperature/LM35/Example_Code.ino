/*
  LM35 - Analog Temperature Sensor
  --------------------------------
  Outputs an analog voltage of 10 mV per degree Celsius (linear).
  No library needed - just an analog read plus a conversion.

  Wiring (Arduino Uno/Nano/Mega, 5V logic):
    LM35 +Vs  -> 5V
    LM35 Vout -> A0
    LM35 GND  -> GND
    (Flat face toward you, pins down: left=+Vs, middle=Vout, right=GND)

  NOTE: Reference code. The conversion below assumes a 5V reference and a
  10-bit ADC (Uno/Nano/Mega). On ESP32/ESP8266 the reference is 3.3V and
  the ADC is 12-bit/10-bit with a non-linear response - adjust accordingly.
*/

const int LM35_PIN = A0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int raw = analogRead(LM35_PIN);
  float voltage = raw * (5.0 / 1023.0); // volts (5V ref, 10-bit ADC)
  float tempC = voltage * 100.0;        // 10 mV/C  ->  multiply by 100

  Serial.print("Temperature: ");
  Serial.print(tempC);
  Serial.println(" C");

  delay(1000);
}
