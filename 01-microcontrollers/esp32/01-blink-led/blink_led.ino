/*
  Blink LED - ESP32
  -----------------
  Board: ESP32 Dev Module (most generic ESP32 dev boards)
  Tests: Onboard LED, confirms IDE + board package + port setup is correct.

  Note: ESP32 onboard LED pin VARIES by board manufacturer.
  GPIO 2 is the most common default - if nothing blinks, check your
  board's datasheet/silkscreen and change LED_PIN below.

  No external wiring required if LED_PIN matches your board.
*/

const int LED_PIN = 2; // Most common onboard LED pin on ESP32 dev boards

void setup() {
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  digitalWrite(LED_PIN, HIGH); // Turn LED on
  delay(1000);                 // Wait 1 second
  digitalWrite(LED_PIN, LOW);  // Turn LED off
  delay(1000);                 // Wait 1 second
}
