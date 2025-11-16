/*#include "mbed.h"
#include "arm_book_lib.h"

//=====[Defines]===========================================
#define NUMBER_OF_AVG_SAMPLES    10
#define TEMPERATURE_THRESHOLD    30.0  // 30°C threshold

//=====[Declaration and initialization of public global objects]===========
AnalogIn lm35(A1);                  // LM35 connected to A1
DigitalOut fanMotor(D7);            // Fan motor control on D7
UnbufferedSerial uartUsb(USBTX, USBRX, 115200);  // Serial communication

//=====[Declaration and initialization of public global variables]========
int lm35SampleIndex = 0;
float lm35ReadingsArray[NUMBER_OF_AVG_SAMPLES];
float lm35ReadingsSum = 0.0;
float lm35ReadingsAverage = 0.0;
float lm35TempC = 0.0;

//=====[Declarations (prototypes) of public functions]===================
void inputsInit();
void outputsInit();
void readTemperature();
void controlFan();
void displayTemperature();

//=====[Main function, the program entry point after power on or reset]==
int main()
{
    inputsInit();
    outputsInit();
    
    // Initialize readings array
    for (int i = 0; i < NUMBER_OF_AVG_SAMPLES; i++) {
        lm35ReadingsArray[i] = 0;
    }
    
    while (true) {
        readTemperature();
        controlFan();
        displayTemperature();
        delay(100);  // 100ms delay between readings
    }
}

//=====[Implementations of public functions]=============================
void inputsInit()
{
    // No additional inputs needed for this implementation
}

void outputsInit()
{
    fanMotor = OFF;  // Start with fan off
}

void readTemperature()
{
    // Read current temperature
    lm35ReadingsArray[lm35SampleIndex] = lm35.read();
    lm35SampleIndex++;
    
    if (lm35SampleIndex >= NUMBER_OF_AVG_SAMPLES) {
        lm35SampleIndex = 0;
    }
    
    // Calculate average
    lm35ReadingsSum = 0.0;
    for (int i = 0; i < NUMBER_OF_AVG_SAMPLES; i++) {
        lm35ReadingsSum += lm35ReadingsArray[i];
    }
    lm35ReadingsAverage = lm35ReadingsSum / NUMBER_OF_AVG_SAMPLES;
    
    // Convert to Celsius (10mV/°C, 3.3V reference)
    lm35TempC = lm35ReadingsAverage * 3.3 / 0.01;
}

void controlFan()
{
    if (lm35TempC > TEMPERATURE_THRESHOLD) {
        fanMotor = ON;  // Turn fan on
    } else {
        fanMotor = OFF; // Turn fan off
    }
}

void displayTemperature()
{
    char str[100];
    int stringLength;
    
    sprintf(str, "Temperature: %.2f \xB0 C\r\n", lm35TempC);
    stringLength = strlen(str);
    uartUsb.write(str, stringLength);
    
    sprintf(str, "Fan status: %s\r\n\r\n", (fanMotor ? "ON" : "OFF"));
    stringLength = strlen(str);
    uartUsb.write(str, stringLength);
}
*/