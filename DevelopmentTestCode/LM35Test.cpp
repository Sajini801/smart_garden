/*
#include "mbed.h"
#include "SerialCom.h"
#include <cstdio>

// Sensor pin setup
AnalogIn tempSensor(A1); // LM35 Temperature Sensor connected to A4

// Helper function to convert a float to a string with two decimal places
// without using %f. Assumes value is non-negative.
void floatToString(float value, char* buffer) {
    int intPart = (int)value;                              // Get the integer part
    int fracPart = (int)((value - intPart) * 100);           // Get fractional part (2 decimals)
    sprintf(buffer, "%d.%02d", intPart, fracPart);           // Use %d formatting only
}

// Build and send the temperature string
void sendTemperature(float temperature, float rawValue) {
    // Calculate voltage based on a 5V reference
    float voltage = rawValue * 5.0;
    
    // Prepare strings for each value
    char tempStr[20];
    char voltStr[20];   
    char rawStr[20];
    
    floatToString(temperature, tempStr);
    floatToString(voltage, voltStr);
    // For raw value, we want three decimals; we can scale it by 1000
    int rawIntPart = (int)(rawValue * 1000);
    int rawFrac = (int)(((rawValue * 1000) - rawIntPart)); // This gives the fractional part in 0 decimals
    // Instead, we can simply use the integer value as a representation since we know rawValue is 0.0-1.0:
    sprintf(rawStr, "%d", rawIntPart);
    
    // Build the final string (raw is displayed as the scaled integer)
    char buffer[100];
    sprintf(buffer, "Raw Value: %s | Voltage: %sV | Temperature: %sC\n", 
            rawStr, voltStr, tempStr);
    sendSerialMessage(buffer);
}

int main() {
    while (true) {
        // Read the raw analog value (0.0 to 1.0)
        float rawValue = tempSensor.read();
        // Convert the raw value to voltage (using a 5V reference)
        float voltage = rawValue * 3.3;
        // For the LM35, temperature in °C is voltage multiplied by 100
        float temperature = voltage * 100.0;

        // Send the temperature reading using our manual conversion
        sendTemperature(temperature, rawValue);

        ThisThread::sleep_for(2000ms);  // Wait for 2 seconds before the next reading
    }
}
*/