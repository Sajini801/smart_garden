/* #include "mbed.h"                
#include "MoistureSensor.h" 
#include "SerialCom.h"     
#include <cstdio>                
UnbufferedSerial pc(USBTX, USBRX, 115200); 

// Define the sensors with both Analog and Digital pins
MoistureSensor moisture_sensor(A0, D7);   // Sensor 1
MoistureSensor moisture_sensor2(A1, D6);  // Sensor 2

int main() {
    while (true) {
        int rawValue = moisture_sensor.readRaw();    // Read raw value for sensor 1
        int rawValue2 = moisture_sensor2.readRaw();  // Read raw value for sensor 2

        // Prepare the message to send
        char buffer[100];
        int len1 = sprintf(buffer, "Sensor One Raw Value: %d\n", rawValue);
        sendSerialMessage(buffer); // Send first sensor value

        int len2 = sprintf(buffer, "Sensor Two Raw Value: %d\n", rawValue2);
        sendSerialMessage(buffer); // Send second sensor value

        thread_sleep_for(5000);  // Wait for 5 seconds before the next reading
    }
}
*/