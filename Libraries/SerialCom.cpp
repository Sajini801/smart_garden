#include "SerialCom.h"
#include "mbed.h"

UnbufferedSerial pc(USBTX, USBRX, 115200);  // USBTX and USBRX are default pins for serial communication on many Nucleo boards

// Function to initialize serial communication
void SerialInit() {
    // No need for pc.begin() since the constructor already initializes it
}

// Function to send a message over serial
void sendSerialMessage(const char* message) {
    pc.write("\n", 1);  // Newline for better readability
    pc.write(message, strlen(message));  // Sends the message
    ThisThread::sleep_for(2000ms);  // Wait for 2 seconds before sending the next message
}

// Function to send an integer value via serial
void sendSerialInt(int value) {
    char buf[32];  // Buffer to store integer as a string
    snprintf(buf, sizeof(buf), "%d", value);  // Convert int to string
    sendSerialMessage(buf);  // Use sendSerialMessage to print integers
}
