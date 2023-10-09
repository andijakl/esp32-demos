#include <Arduino.h>
#include <Wire.h>
#include "MAX30105.h"

// Based on:
// https://lastminuteengineers.com/max30102-pulse-oximeter-heart-rate-sensor-arduino-tutorial/

MAX30105 particleSensor;

void setup()
{
  Serial.begin(115200);

  // NOT IN EXAMPLE - can be configured for esp32
  Wire.setPins(21, 22); // SDA, SCL

  // Initialize sensor
  if (particleSensor.begin() == false)
  {
    Serial.println("MAX30102 was not found. Please check wiring/power.");
    while (1)
      ;
  }

  // The LEDs are very low power and won't affect the temp reading much but
  // you may want to turn off the LEDs to avoid any local heating
  particleSensor.setup(0); // Configure sensor. Turn off LEDs

  particleSensor.enableDIETEMPRDY(); // Enable the temp ready interrupt. This is required.
}

void loop()
{
  float temperature = particleSensor.readTemperature();

  Serial.print("temperatureC=");
  Serial.print(temperature, 4);

  float temperatureF = particleSensor.readTemperatureF();

  Serial.print(" temperatureF=");
  Serial.print(temperatureF, 4);

  Serial.println();
}
