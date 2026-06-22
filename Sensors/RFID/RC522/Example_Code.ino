/*
  RC522 (MFRC522) - 13.56 MHz RFID Reader (SPI)
  ---------------------------------------------
  Reads the UID of ISO/IEC 14443A / MIFARE cards and tags over SPI.

  Library required (install via Library Manager):
    - "MFRC522" by GithubCommunity (miguelbalboa)

  Wiring (Arduino Uno/Nano - SPI):
    RC522 SDA(SS) -> D10
    RC522 SCK     -> D13
    RC522 MOSI    -> D11
    RC522 MISO    -> D12
    RC522 RST     -> D9
    RC522 3.3V    -> 3.3V   *** MUST be 3.3V - 5V can damage the module ***
    RC522 GND     -> GND
    (Mega: SS->53? use any free pin, SCK->52, MOSI->51, MISO->50, RST->5)

  NOTE: Reference code. The SDA pin is labeled SS on some boards. The card
  UID is NOT secure (cheap cards can be cloned) - do not use it alone for
  real security.
*/

#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 10
#define RST_PIN 9

MFRC522 mfrc522(SS_PIN, RST_PIN);

void setup() {
  Serial.begin(9600);
  SPI.begin();
  mfrc522.PCD_Init();
  Serial.println("Scan an RFID card/tag...");
}

void loop() {
  // Look for a new card
  if (!mfrc522.PICC_IsNewCardPresent()) return;
  if (!mfrc522.PICC_ReadCardSerial()) return;

  Serial.print("Card UID:");
  for (byte i = 0; i < mfrc522.uid.size; i++) {
    Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
    Serial.print(mfrc522.uid.uidByte[i], HEX);
  }
  Serial.println();

  mfrc522.PICC_HaltA(); // Stop reading this card
}
