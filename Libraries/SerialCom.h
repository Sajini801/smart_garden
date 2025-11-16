// SerialCom.h
#ifndef SERIAL_COM_H
#define SERIAL_COM_H

#include "mbed.h"

extern UnbufferedSerial pc;  // Declare the pc object so it can be used globally

// Function to initialize serial communication
void SerialInit();

// Function to send a serial message
void sendSerialMessage(const char* message);

// Function to send an integer value via serial
void sendSerialInt(int value);

#endif
