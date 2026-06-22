/*
  MQ-2 - Flammable Gas & Smoke Sensor
  -----------------------------------
  SnO2 semiconductor sensor sensitive to LPG, propane, methane, hydrogen,
  and smoke. The module exposes an analog output (AO) and a digital
  threshold output (DO, set by the onboard potentiometer).

  Wiring (Arduino Uno/Nano/Mega):
    MQ-2 VCC -> 5V   (the heater needs 5V; do NOT power from 3.3V)
    MQ-2 GND -> GND
    MQ-2 AO  -> A0   (analog gas level)
    MQ-2 DO  -> D2   (optional: HIGH/LOW based on the pot threshold)

  *** IMPORTANT - this sensor needs time, not just code: ***
   - First-ever use: "burn-in" for 24-48 hours for stable readings.
   - Every session: allow ~20 minutes warm-up before trusting values.
   - The heater draws ~150 mA - power it from 5V with a common ground,
     not from a microcontroller pin.
   - Converting the raw value to ppm requires calibration against the
     datasheet Rs/Ro curve; the raw analog value alone is relative only.

  NOTE: Reference code. Treat the output as a relative gas level.
*/

const int MQ2_AO_PIN = A0;
const int MQ2_DO_PIN = 2;

void setup() {
  Serial.begin(9600);
  pinMode(MQ2_DO_PIN, INPUT);
}

void loop() {
  int gasLevel = analogRead(MQ2_AO_PIN);   // relative, 0-1023
  int threshold = digitalRead(MQ2_DO_PIN); // HIGH/LOW per onboard pot

  Serial.print("Gas level (analog): ");
  Serial.print(gasLevel);
  Serial.print("   Threshold (DO): ");
  Serial.println(threshold == HIGH ? "HIGH" : "LOW");

  delay(500);
}
