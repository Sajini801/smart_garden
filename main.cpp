#include "MoistureSensor.h"
#include "LightSensor.h"
#include "FanControl.h"
#include "SerialCom.h"
#include "mbed.h"

// Initialise sensors and components
MoistureSensor moistureSensor(A4, A0, D4, D3, D7, D6);  // Moisture sensor (A4 & A0, Power pins D1 & D2, LED pins D7 & D6)
//Sensor 1 = A4 Sensor 2 = A0

// Function to initialize the system
void initializeSystem() {
    SerialInit();               // Initialize serial communication
    LightSensorInit();          // Initialize light sensor system
    initializeFanControl();     // Initialize fan control system
    sendSerialMessage("System Initialised. Garden Monitoring ON\n");
}

// Main loop to update sensor values and control outputs
int main() {
    initializeSystem();  // Initialise system once at startup

    char buffer[64];
    while (true) {
        // Read and process moisture sensor 1
        int moistureValue1 = moistureSensor.readMoistureSensor1();
        int moisturePercentage1 = moistureSensor.convertToMoisturePercentage(moistureValue1);
        moistureSensor.controlLedBasedOnMoisture(moisturePercentage1, moistureSensor.getLed1());
        sprintf(buffer, "Moisture Sensor 1 Value: %d, Moisture: %d%%\n", moistureValue1, moisturePercentage1);
        sendSerialMessage(buffer);

        // Read and process moisture sensor 2
        int moistureValue2 = moistureSensor.readMoistureSensor2();
        int moisturePercentage2 = moistureSensor.convertToMoisturePercentage(moistureValue2);
        moistureSensor.controlLedBasedOnMoisture(moisturePercentage2, moistureSensor.getLed2());
        sprintf(buffer, "Moisture Sensor 2 Value: %d, Moisture: %d%%\n", moistureValue2, moisturePercentage2);
        sendSerialMessage(buffer);

        ThisThread::sleep_for(1000ms);  // Delay to avoid flooding the serial output
    

        // Update light sensor and control LED
        UpdateLightSensor();  // Call to update light sensor and LED

        // Update fan control
        updateFanControl();

        ThisThread::sleep_for(1000ms);  // Delay to avoid flooding the serial output

        // Read and process temperature sensor
        float temperature = readTemperatureCelsius();
        if (temperature >= TEMP_THRESHOLD) {
            fanRelay = 0;  // Turn on fan if temperature exceeds threshold
            sendSerialMessage("Fan ON (temperature exceeded threshold)\n");
        } else {
            fanRelay = 1;  // Turn off fan if temperature is below threshold
            sendSerialMessage("Fan OFF (temperature below threshold)\n");
        }

        // Print temperature
        char tempBuffer[20];
        formatFloat(temperature, tempBuffer);
        sprintf(buffer, "Temperature: %sC\n", tempBuffer);
        sendSerialMessage(buffer);

        ThisThread::sleep_for(1000ms);  // Delay to avoid flooding the serial output
    }
}
