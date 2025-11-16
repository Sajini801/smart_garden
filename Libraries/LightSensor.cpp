#include "LightSensor.h"
#include "mbed.h"
#include "SerialCom.h"

// Global LED pin and light sensor pin
DigitalOut lightLed(D1);    // LED connected to pin D2
AnalogIn lightSensor(A2);   // Light sensor connected to pin A2

// Threshold for light level
const int LIGHT_THRESHOLD = 150;  // Set this threshold based on your requirements

// Function to initialize the light sensor
void LightSensorInit() {
    // If you need any specific setup for the light sensor, add it here
    lightLed = 0;  // Ensure LED is off at initialization
}

// Function to read the light sensor and return the value as an integer (12-bit value)
int ReadLightSensor() {
    return static_cast<int>(lightSensor.read() * 4095);  // Convert to 12-bit value (0-4095)
}

// Function to update the light sensor and control the LED
void UpdateLightSensor() {
    // Read the light value
    int lightValue = ReadLightSensor();  // Get the light sensor value as an integer

    // Print the light value as an integer
    char buffer[64];
    sprintf(buffer, "Light Value: %d\n", lightValue);
    sendSerialMessage(buffer);  // Send the value to serial

    // Control the LED based on light value
    if (lightValue < LIGHT_THRESHOLD) {
        lightLed = 1;  // Turn LED on if light level is below threshold
        sendSerialMessage("LED is ON\n");
    } else {
        lightLed = 0;  // Turn LED off if light level is above threshold
        sendSerialMessage("LED is OFF\n");
    }
}
