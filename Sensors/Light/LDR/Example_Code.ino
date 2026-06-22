/*
  LDR - Light Dependent Resistor (Photoresistor)
  ----------------------------------------------
  Resistance drops as light increases. Read it as an analog voltage using
  a voltage-divider circuit. No library needed.

  Voltage divider wiring (Arduino Uno/Nano/Mega):
    5V ---[ LDR ]---+---[ 10k resistor ]--- GND
                    |
                    +--> A0

  With this arrangement the A0 reading RISES as light increases. (Swap the
  LDR and resistor positions to invert the behavior.)

  NOTE: Reference code. analogRead returns 0-1023 on Uno/Nano/Mega.
  "Light" here is a raw relative value, not calibrated lux.
*/

const int LDR_PIN = A0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int lightValue = analogRead(LDR_PIN); // 0 (dark) .. 1023 (bright)

  Serial.print("Light level: ");
  Serial.println(lightValue);

  // Example threshold action:
  // if (lightValue < 300) Serial.println("It's dark");

  delay(500);
}
