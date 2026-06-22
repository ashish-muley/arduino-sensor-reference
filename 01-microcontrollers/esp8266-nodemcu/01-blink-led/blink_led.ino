/*
  Blink LED - ESP8266 / NodeMCU
  -----------------------------
  Board: NodeMCU 1.0 (ESP-12E Module)
  Tests: Onboard LED, confirms IDE + board package + port setup is correct.

  IMPORTANT: The onboard LED on most ESP8266/NodeMCU boards is ACTIVE LOW.
  This means LOW = LED ON, HIGH = LED OFF (opposite of Uno/Mega/ESP32).
  This sketch accounts for that already.

  No external wiring required - uses the onboard LED (GPIO2 / D4).
*/

const int LED_PIN = 2; // GPIO2, labeled "D4" on NodeMCU boards

void setup() {
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  digitalWrite(LED_PIN, LOW);  // LOW = LED ON (active LOW)
  delay(1000);                 // Wait 1 second
  digitalWrite(LED_PIN, HIGH); // HIGH = LED OFF
  delay(1000);                 // Wait 1 second
}
