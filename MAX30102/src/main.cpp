#include <Arduino.h>
#include <Wire.h>
#include "MAX30105.h"

// Based on:
// https://github.com/sparkfun/SparkFun_MAX3010x_Sensor_Library
// https://lastminuteengineers.com/max30102-pulse-oximeter-heart-rate-sensor-arduino-tutorial/

MAX30105 particleSensor;

void setup()
{
  Serial.begin(115200);

  // Initialize sensor
  if (particleSensor.begin() == false)
  {
    Serial.println("MAX30102 was not found. Please check wiring/power.");
    while (1)
      ;
  }

  particleSensor.setup(); // Configure sensor. Use 6.4mA for LED drive
}

void loop()
{
  // Better readable output for console
  // Serial.print(" R[");
  // Serial.print(particleSensor.getRed());
  // Serial.print("] IR[");
  // Serial.print(particleSensor.getIR());
  // Serial.println("]");

  int red = particleSensor.getRed();
  int ir = particleSensor.getIR();
  Serial.print(red);

  // For Arduino Serial Plotter
  Serial.print(particleSensor.getRed());
  Serial.print(", ");
  Serial.println(particleSensor.getIR());
}
