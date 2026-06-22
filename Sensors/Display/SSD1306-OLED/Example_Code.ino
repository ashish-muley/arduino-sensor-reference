/*
  SSD1306 - 128x64 OLED Display (I2C)
  -----------------------------------
  Small monochrome OLED, very common for sensor dashboards. I2C address is
  usually 0x3C (sometimes 0x3D).

  Libraries required (install via Library Manager):
    - "Adafruit SSD1306" by Adafruit
    - "Adafruit GFX Library" by Adafruit (dependency)
    - "Adafruit BusIO" by Adafruit (dependency)

  Wiring (Arduino Uno/Nano - I2C):
    OLED VCC -> 3.3V or 5V (most modules accept both)
    OLED GND -> GND
    OLED SCL -> A5 (Uno/Nano) | 21 (Mega) | GPIO22 (ESP32)
    OLED SDA -> A4 (Uno/Nano) | 20 (Mega) | GPIO21 (ESP32)

  NOTE: Reference code. If the screen stays black, confirm the I2C address
  (0x3C vs 0x3D) with an I2C scanner.
*/

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1     // -1 = share Arduino reset pin
#define SCREEN_ADDRESS 0x3C

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() {
  Serial.begin(9600);

  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println("SSD1306 allocation failed - check address/wiring.");
    for (;;); // halt
  }

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println(F("Arduino Sensor"));
  display.println(F("Reference"));
  display.setCursor(0, 40);
  display.setTextSize(2);
  display.println(F("Hello!"));
  display.display();
}

void loop() {
  // Static demo - nothing to update here.
}
