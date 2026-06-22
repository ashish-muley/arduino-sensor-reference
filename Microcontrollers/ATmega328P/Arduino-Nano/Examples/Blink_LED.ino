/*
  Blink LED - Arduino Nano
  ------------------------
  Board: Arduino Nano
  Tests: Onboard LED, confirms IDE + board + processor + port setup is correct.

  No external wiring required - uses the onboard LED next to pin 13.

  Note: If upload fails with "programmer not responding", try changing
  Tools -> Processor to "ATmega328P (Old Bootloader)" - common on clone boards.
*/

const int LED_PIN = 13; // Onboard LED on Arduino Nano

void setup() {
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  digitalWrite(LED_PIN, HIGH); // Turn LED on
  delay(1000);                 // Wait 1 second
  digitalWrite(LED_PIN, LOW);  // Turn LED off
  delay(1000);                 // Wait 1 second
}
