/*
  PIR Motion Sensor (HC-SR501)
  ----------------------------
  Passive infrared motion detector. Outputs a digital HIGH when motion is
  detected. No library needed - it is a simple digital input.

  Wiring (Arduino Uno/Nano/Mega):
    HC-SR501 VCC -> 5V  (module accepts ~4.5-20V; output logic is 3.3V)
    HC-SR501 OUT -> D2
    HC-SR501 GND -> GND

  The module has two potentiometers (sensitivity and time-delay) and a
  jumper to select trigger mode (single vs repeat). After power-on it needs
  ~30-60 seconds to stabilize before readings are reliable.

  NOTE: Reference code. The OUT pin idles LOW and goes HIGH on motion.
*/

const int PIR_PIN = 2;
const int LED_PIN = 13; // Onboard LED as a visual indicator

void setup() {
  Serial.begin(9600);
  pinMode(PIR_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  Serial.println("PIR warming up...");
  delay(2000);
}

void loop() {
  int motion = digitalRead(PIR_PIN);

  if (motion == HIGH) {
    digitalWrite(LED_PIN, HIGH);
    Serial.println("Motion detected!");
  } else {
    digitalWrite(LED_PIN, LOW);
  }

  delay(200);
}
