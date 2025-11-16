#include "MoistureSensor.h"

// Constructor to initialize pins
MoistureSensor::MoistureSensor(PinName sensorPin1, PinName sensorPin2, PinName powerPin1, PinName powerPin2, PinName ledPin1, PinName ledPin2)
    : moistureSensor1(sensorPin1), moistureSensor2(sensorPin2), sensorPower1(powerPin1), sensorPower2(powerPin2), led1(ledPin1), led2(ledPin2) {}

// Function to read sensor 1
int MoistureSensor::readMoistureSensor1() {
    sensorPower1 = 1;  // Power on the sensor
    ThisThread::sleep_for(200ms);  // Wait for sensor to stabilize
    int rawValue = moistureSensor1.read() * 4095;
    sensorPower1 = 0;
    return rawValue;
}

// Function to read sensor 2 with an added 1000 offset
int MoistureSensor::readMoistureSensor2() {
    sensorPower2 = 1;  // Power on the sensor
    ThisThread::sleep_for(200ms);  // Wait for sensor to stabilize
    int rawValue = moistureSensor2.read() * 4095;
    sensorPower2 = 0;

    // Add 1000 to the sensor 2 reading to correct the offset
    rawValue += 1000;

    return rawValue;
}

// Convert the raw sensor value to moisture percentage
int MoistureSensor::convertToMoisturePercentage(int rawValue) {
    if (rawValue > DRY_VALUE) rawValue = DRY_VALUE;
    if (rawValue < WET_VALUE) rawValue = WET_VALUE;

    float percent = ((float)(DRY_VALUE - rawValue) / (DRY_VALUE - WET_VALUE)) * 100.0;
    return (int)percent;
}

// Control the LED based on the moisture percentage
void MoistureSensor::controlLedBasedOnMoisture(int moisturePercentage, DigitalOut& ledPin) {
    if (moisturePercentage < 30) {
        ledPin = 1;  // Turn LED ON for dry soil
    } else {
        ledPin = 0;  // Turn LED OFF for moist or wet soil
    }
}

// Getters for LEDs
DigitalOut& MoistureSensor::getLed1() {
    return led1;
}

DigitalOut& MoistureSensor::getLed2() {
    return led2;
}
