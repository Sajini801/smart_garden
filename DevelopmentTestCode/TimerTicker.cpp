/* #include <mbed.h>
#include <cstdio>
#include "SerialCom.h"  

// Timer to track elapsed time
Timer timer;

// LED output
DigitalOut led(D2);  // LED for visual feedback

// Ticker for reading time every 1 second
Ticker timeTicker;

// Create an EventQueue for handling serial messages in thread context
EventQueue eventQueue(32 * EVENTS_EVENT_SIZE);

// This function will be called by the EventQueue in thread context
void queueSendSerialMessage(const char* msg) {
    sendSerialMessage(msg);
}

// Update time and control LED based on conditions
void updateTime() {
    // Read current time in milliseconds and convert to seconds
    int currentTime = timer.read_ms();
    int seconds = currentTime / 1000;

    // Prepare the message
    char buffer[50];
    sprintf(buffer, "Time: %d seconds\n", seconds);
    // Post the serial message to the event queue
    eventQueue.call(queueSendSerialMessage, buffer);

    // Toggle LED every 10 seconds as an example
    if (seconds % 10 == 0) {
        led = !led;
        eventQueue.call(queueSendSerialMessage, "LED toggled every 10 seconds\n");
    }
}

int main() {
    // Send initial message (this runs in main thread so it's safe)
    sendSerialMessage("Program Started\n");

    // Start the timer
    timer.start();

    // Attach the updateTime function to be called every second by the Ticker
    timeTicker.attach(&updateTime, 1s);

    // Dispatch the event queue forever (this runs in the main thread)
    eventQueue.dispatch_forever();

    // The program will never reach here
    while (true) {}
}
*/