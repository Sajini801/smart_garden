#ifndef MOISTURESENSOR_H
#define MOISTURESENSOR_H

#include "mbed.h"

class MoistureSensor {
public:
    MoistureSensor(PinName sensorPin1, PinName sensorPin2, PinName powerPin1, PinName powerPin2, PinName ledPin1, PinName ledPin2);

    // Function to read moisture sensor 1
    int readMoistureSensor1();

    // Function to read moisture sensor 2 with an added 1000 offset
    int readMoistureSensor2();

    // Convert raw sensor value to moisture percentage
    int convertToMoisturePercentage(int rawValue);

    // Control the LED based on moisture level
    void controlLedBasedOnMoisture(int moisturePercentage, DigitalOut& ledPin);

    // Getters for LEDs
    DigitalOut& getLed1();
    DigitalOut& getLed2();

private:
    AnalogIn moistureSensor1;
    AnalogIn moistureSensor2;
    DigitalOut sensorPower1;
    DigitalOut sensorPower2;
    DigitalOut led1;
    DigitalOut led2;

    // Constants for calibration
    const int DRY_VALUE = 3500;
    const int WET_VALUE = 2500;
};

#endif
