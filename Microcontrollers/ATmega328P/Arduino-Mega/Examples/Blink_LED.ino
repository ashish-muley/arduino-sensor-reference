/*
  Blink LED - Arduino Mega 2560
  -----------------------------
  Board: Arduino Mega 2560
  Tests: Onboard LED, confirms IDE + board + processor + port setup is correct.

  No external wiring required - uses the onboard LED next to pin 13.
*/

const int LED_PIN = 13; // Onboard LED on Arduino Mega 2560

void setup() {
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  digitalWrite(LED_PIN, HIGH); // Turn LED on
  delay(1000);                 // Wait 1 second
  digitalWrite(LED_PIN, LOW);  // Turn LED off
  delay(1000);                 // Wait 1 second
}
