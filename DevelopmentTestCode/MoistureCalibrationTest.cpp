/*#include "mbed.h"                // For mbed-specific functions
#include "MoistureSensor.h" // Include the custom MoistureSensor class
#include "SerialCom.h"     // Include custom Serial Communication functions
#include <cstdio>                 // For sprintf

// Sensor Pin Setup
AnalogIn moistureSensor1(A1);
DigitalOut sensorPower1(D1);

AnalogIn moistureSensor2(A2);
DigitalOut sensorPower2(D2);

// Serial Communication
UnbufferedSerial pc(USBTX, USBRX, 9600);  // TX, RX, Baud rate

// Moisture Conversion
int convertToMoisturePercentage(int rawValue, int dryValue = 2150, int wetValue = 1200) {
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

// Main
int main() {
    pc.write("Starting Moisture Calibration Test...\n", 37);

    while (true) {
        sensorPower1 = 1;
        sensorPower2 = 1;

        ThisThread::sleep_for(1s); // Wait for stable reading

        int raw1 = moistureSensor1.read() * 4095;
        int percent1 = convertToMoisturePercentage(raw1);
        const char* label1 = getMoistureLabel(percent1);

        int raw2 = moistureSensor2.read() * 4095;
        int percent2 = convertToMoisturePercentage(raw2);
        const char* label2 = getMoistureLabel(percent2);

        char buffer[100];
        int len = sprintf(buffer, "Sensor 1: Raw = %d | %d%% | %s\n", raw1, percent1, label1);
        pc.write(buffer, len);

        len = sprintf(buffer, "Sensor 2: Raw = %d | %d%% | %s\n\n", raw2, percent2, label2);
        pc.write(buffer, len);

        sensorPower1 = 0;
        sensorPower2 = 0;

        ThisThread::sleep_for(5s);
    }
}
*/