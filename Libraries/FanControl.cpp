#include "FanControl.h"
#include "SerialCom.h"
#include "Utility.h"  // Include shared utility -- For Converting Floating Point Numbers 

// === Pin Setup ===
AnalogIn tempSensor(A1);         // LM35 analog temperature sensor
DigitalOut fanRelay(D2);         // Relay module controlling fan (LOW = ON, HIGH = OFF)

// === Threshold ===
const int TEMP_THRESHOLD = 32;   // Temperature threshold in °C

// === Helper: Convert and Read Temperature ===
float readTemperatureCelsius() {
    float raw = tempSensor.read();      // Returns value between 0.0 - 1.0
    float voltage = raw * 3.3;          // Convert to voltage (assuming 5V reference)
    return voltage * 100.0;             // LM35 gives 10mV per °C → multiply by 100
}

// === Initialize Fan Control ===
void initializeFanControl() {
    // Initialize any pins or variables here if needed
    fanRelay = 1;  // Ensure the fan starts off
}

// === Update Fan Control ===
void updateFanControl() {
    static char tempBuffer[20];
    float temperature = readTemperatureCelsius();
    formatFloat(temperature, tempBuffer);  // Use shared function to format float

    // === Control Relay ===
    if (temperature >= TEMP_THRESHOLD) {
        fanRelay = 0; // LOW → Relay ON
        sendSerialMessage("Fan ON (temperature exceeded threshold)");
    } else {
        fanRelay = 1; // HIGH → Relay OFF
        sendSerialMessage("Fan OFF (temperature below threshold)");
    }

    // === Print Temperature ===
    char msg[100];
    snprintf(msg, sizeof(msg), "Temperature: %sC", tempBuffer);
    sendSerialMessage(msg);
}
