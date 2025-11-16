#ifndef LIGHTSENSOR_H
#define LIGHTSENSOR_H

#include "mbed.h"

extern DigitalOut lightLed;   // LED pin
extern AnalogIn lightSensor;  // Light sensor pin

void LightSensorInit();       // Initialize light sensor
int ReadLightSensor();       // Function to read the light sensor value as an integer
void UpdateLightSensor();    // Function to update the light sensor value and control LED

#endif
