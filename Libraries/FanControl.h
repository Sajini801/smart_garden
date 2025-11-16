#ifndef FANCONTROL_H
#define FANCONTROL_H

#include "mbed.h"

// Declare external variables
extern DigitalOut fanRelay;
extern const int TEMP_THRESHOLD;

// Declare functions
float readTemperatureCelsius();
void formatFloat(float value, char* buffer);
void initializeFanControl();
void updateFanControl();

#endif
