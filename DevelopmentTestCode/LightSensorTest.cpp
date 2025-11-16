/*#include "mbed.h"
#include "SerialCom.h"  // Your SerialCom wrapper for printing
#include "RTC.h"        // Include the RTC header file

// Hardware setup
AnalogIn lightSensor(A2);  // Light sensor on A2
DigitalOut led(D2);        // LED on D2

// Threshold
const int LIGHT_THRESHOLD = 20;

// Main loop
int main() {
    char buffer[50];
    sendSerialMessage("Garden system starting...\n");

    // Initialize RTC
    initializeRTC();  // Initialize the RTC using the RTC module

    ThisThread::sleep_for(2s);  // Delay for peripherals to settle

    while (true) {
        // Check if current time is in the range (6 AM to 6 PM)
        if (isTimeInRange()) {
            // Read light sensor value (0.0 to 1.0)
            float rawValue = lightSensor.read();
            int lightValue = rawValue * 4095;  // Convert to 12-bit ADC value

            // Send light value via serial
            sprintf(buffer, "Light Value: %d\n", lightValue);
            sendSerialMessage(buffer);

            // Turn on/off LED based on light sensor value
            led = (lightValue < LIGHT_THRESHOLD) ? 1 : 0;
        } else {
            // Turn off LED if time is outside the range
            led = 0;
        }

        ThisThread::sleep_for(1s);  // Delay before the next reading
    }
}
*/