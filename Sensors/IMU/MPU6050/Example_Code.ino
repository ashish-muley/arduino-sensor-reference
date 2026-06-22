/*
  MPU6050 - 6-Axis Accelerometer + Gyroscope (I2C)
  ------------------------------------------------
  3-axis accelerometer + 3-axis gyroscope on a single chip. I2C address
  0x68 (or 0x69 if AD0 is pulled HIGH).

  Libraries required (install via Library Manager):
    - "Adafruit MPU6050" by Adafruit
    - "Adafruit Unified Sensor" by Adafruit (dependency)
    - "Adafruit BusIO" by Adafruit (dependency)

  Wiring (Arduino Uno/Nano - I2C):
    MPU6050 VCC -> 5V (module has an onboard 3.3V regulator) or 3.3V
    MPU6050 GND -> GND
    MPU6050 SCL -> A5 (Uno/Nano)   | 21 (Mega) | GPIO22 (ESP32) | D1 (NodeMCU)
    MPU6050 SDA -> A4 (Uno/Nano)   | 20 (Mega) | GPIO21 (ESP32) | D2 (NodeMCU)

  NOTE: Reference code. If begin() fails, run an I2C scanner to confirm the
  address (0x68 vs 0x69).
*/

#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>

Adafruit_MPU6050 mpu;

void setup() {
  Serial.begin(115200);
  while (!Serial) delay(10);

  if (!mpu.begin()) {
    Serial.println("Failed to find MPU6050 - check wiring/address.");
    while (1) delay(10);
  }
  Serial.println("MPU6050 ready");

  mpu.setAccelerometerRange(MPU6050_RANGE_8_G);
  mpu.setGyroRange(MPU6050_RANGE_500_DEG);
  mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);
}

void loop() {
  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);

  Serial.print("Accel (m/s^2)  X:"); Serial.print(a.acceleration.x);
  Serial.print(" Y:"); Serial.print(a.acceleration.y);
  Serial.print(" Z:"); Serial.print(a.acceleration.z);

  Serial.print("  |  Gyro (rad/s)  X:"); Serial.print(g.gyro.x);
  Serial.print(" Y:"); Serial.print(g.gyro.y);
  Serial.print(" Z:"); Serial.print(g.gyro.z);

  Serial.print("  |  Temp: "); Serial.print(temp.temperature);
  Serial.println(" C");

  delay(500);
}
