/*#include "mbed.h"
#include "MoistureSensor.h"
#include "SerialCom.h"

// Declare LEDs as DigitalOut objects
DigitalOut led1(D3);  // LED for sensor 1 (dry soil indication)
DigitalOut led2(D4);  // LED for sensor 2 (dry soil indication)

// Initialize sensors with analog pin, power pin, and LED pin
MoistureSensor sensor1(A0, D5, D3);  // Sensor 1 with LED1 on pin D3
MoistureSensor sensor2(A1, D6, D4);  // Sensor 2 with LED2 on pin D4

// Calibration values
const int DRY_VALUE = 2150;
const int WET_VALUE = 1200;

int convertToMoisturePercentage(int rawValue, int dryValue = DRY_VALUE, int wetValue = WET_VALUE) {
    if (rawValue > dryValue) rawValue = dryValue;
    if (rawValue < wetValue) rawValue = wetValue;

    float percent = ((float)(dryValue - rawValue) / (dryValue - wetValue)) * 100.0;
    return (int)percent;
}

const char* getMoistureLabel(int percentage) {
    if (percentage < 30) return "Dry";
    else if (percentage < 70) return "Moist";
    else return "Wet";
}

int main() {
    sendSerialMessage("Starting Moisture Calibration Test...");

    while (true) {
        // Read moisture for sensor 1 and control LED
        int rawValue1 = sensor1.readMoisture();
        int percentage1 = convertToMoisturePercentage(rawValue1);
        const char* label1 = getMoistureLabel(percentage1);
        sensor1.controlLedBasedOnMoisture(percentage1);  // Update LED for sensor 1
        sendSerialMessage("Sensor 1 Moisture Level Updated"); // Send message via serial

        // Read moisture for sensor 2 and control LED
        int rawValue2 = sensor2.readMoisture();
        int percentage2 = convertToMoisturePercentage(rawValue2);
        const char* label2 = getMoistureLabel(percentage2);
        sensor2.controlLedBasedOnMoisture(percentage2);  // Update LED for sensor 2
        sendSerialMessage("Sensor 2 Moisture Level Updated"); // Send message via serial

        // Send moisture data over serial
        char buffer[100];
        int len = sprintf(buffer, "Sensor 1 - Raw: %d | %d%% | %s\n", rawValue1, percentage1, label1);
        sendSerialMessage(buffer);

        len = sprintf(buffer, "Sensor 2 - Raw: %d | %d%% | %s\n\n", rawValue2, percentage2, label2);
        sendSerialMessage(buffer);

        ThisThread::sleep_for(2000ms);  // Delay before next reading
    }
}
*/