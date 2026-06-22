/*
  HC-SR04 - Ultrasonic Distance Sensor
  ------------------------------------
  Measures 2-400 cm by timing a 40 kHz ultrasonic echo. No library needed.

  How it works: a 10 us pulse on TRIG fires an 8-cycle 40 kHz burst.
  ECHO then goes HIGH for a duration equal to the round-trip time of flight.

  Wiring (Arduino Uno/Nano/Mega, 5V logic):
    HC-SR04 VCC  -> 5V
    HC-SR04 TRIG -> D9
    HC-SR04 ECHO -> D10
    HC-SR04 GND  -> GND

  *** 3.3V BOARDS (ESP32/ESP8266): the ECHO pin outputs 5V and is NOT
      3.3V-safe. Use a voltage divider (e.g. 1k + 2k) on ECHO, or a
      logic-level shifter, to avoid damaging the GPIO. ***

  NOTE: Reference code. Distance = (echo time us * speed of sound) / 2.
  Speed of sound ~ 0.0343 cm/us at room temperature.
*/

const int TRIG_PIN = 9;
const int ECHO_PIN = 10;

void setup() {
  Serial.begin(9600);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
}

void loop() {
  // Send a clean 10 us trigger pulse
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  long durationUs = pulseIn(ECHO_PIN, HIGH); // round-trip time
  float distanceCm = durationUs * 0.0343 / 2.0;

  if (durationUs == 0) {
    Serial.println("No echo (out of range or wiring issue)");
  } else {
    Serial.print("Distance: ");
    Serial.print(distanceCm);
    Serial.println(" cm");
  }

  delay(200);
}
