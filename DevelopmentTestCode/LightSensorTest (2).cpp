/* #include <mbed.h>
#include "SerialCom.h"  
#include <cstring>
#include "FlashRTC.h"  

// Hardware setup
AnalogIn lightSensor(A2);  // Light sensor on A2
DigitalOut led(D2);        // LED on D2

// RTC handle
RTC_HandleTypeDef hrtc;

// Threshold
const int LIGHT_THRESHOLD = 20;

// --- RTC Initialization with persistent backup ---
void initializeRTC() {
    sendSerialMessage("Initializing RTC...\n");

    // Enable power interface and backup access
    __HAL_RCC_PWR_CLK_ENABLE();
    HAL_PWR_EnableBkUpAccess();

    // Enable RTC Clock
    __HAL_RCC_RTC_ENABLE();

    // Configure RTC clock source (LSI)
    RCC_OscInitTypeDef RCC_OscInitStruct = {0};
    RCC_PeriphCLKInitTypeDef PeriphClkInitStruct = {0};

    RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_LSI;
    RCC_OscInitStruct.LSIState = RCC_LSI_ON;
    RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;

    if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK) {
        sendSerialMessage("RTC Clock Config Failed!\n");
        while (1);
    }

    PeriphClkInitStruct.PeriphClockSelection = RCC_PERIPHCLK_RTC;
    PeriphClkInitStruct.RTCClockSelection = RCC_RTCCLKSOURCE_LSI;

    if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInitStruct) != HAL_OK) {
        sendSerialMessage("RTC Peripheral Clock Config Failed!\n");
        while (1);
    }

    // Check if RTC time exists in flash
    uint8_t hour, min, sec;
    if (!readTimeFromFlash(hour, min, sec)) {
        sendSerialMessage("Setting initial RTC time...\n");

        RTC_TimeTypeDef sTime = {0};
        RTC_DateTypeDef sDate = {0};

        sTime.Hours = hour;
        sTime.Minutes = min;
        sTime.Seconds = sec;
        if (HAL_RTC_SetTime(&hrtc, &sTime, RTC_FORMAT_BIN) != HAL_OK) {
            sendSerialMessage("Failed to set RTC Time!\n");
        }

        sDate.WeekDay = RTC_WEEKDAY_MONDAY;
        sDate.Month = RTC_MONTH_APRIL;
        sDate.Date = 5;
        sDate.Year = 25; // = 2025
        if (HAL_RTC_SetDate(&hrtc, &sDate, RTC_FORMAT_BIN) != HAL_OK) {
            sendSerialMessage("Failed to set RTC Date!\n");
        }
    } else {
        sendSerialMessage("RTC already initialized, keeping current time.\n");
    }

    // Ensure RTC registers are synchronized
    if (HAL_RTC_WaitForSynchro(&hrtc) != HAL_OK) {
        sendSerialMessage("RTC Sync Failed!\n");
        while (1);
    }

    sendSerialMessage("RTC Initialized.\n");
}

// Function to check if current time is within the specified range (e.g., daytime)
bool isTimeInRange() {
    RTC_TimeTypeDef sTime = {0};
    RTC_DateTypeDef sDate = {0};  // Added to unlock RTC registers
    HAL_RTC_GetTime(&hrtc, &sTime, RTC_FORMAT_BIN);
    HAL_RTC_GetDate(&hrtc, &sDate, RTC_FORMAT_BIN);  // This call is necessary!

    char buffer[50];
    int len = sprintf(buffer, "RTC Time: %02d:%02d:%02d\n", sTime.Hours, sTime.Minutes, sTime.Seconds);
    sendSerialMessage(buffer);

    return (sTime.Hours >= 6 && sTime.Hours < 18);
}

int main() {
    char buffer[50];
    sendSerialMessage("Garden system starting...\n");
    ThisThread::sleep_for(2s);  // Delay for peripherals to settle

    // Initialize RTC
    initializeRTC();

    RTC_TimeTypeDef sTime = {0};

    while (true) {
        // Read current time
        HAL_RTC_GetTime(&hrtc, &sTime, RTC_FORMAT_BIN);
        
        // Save time to flash every minute
        if (sTime.Seconds == 0) {  // Adjust the timing here for how often you want to save
            saveTimeToFlash(sTime.Hours, sTime.Minutes, sTime.Seconds);
        }

        // Process light sensor logic
        if (isTimeInRange()) {
            float rawValue = lightSensor.read();          // 0.0 to 1.0
            int lightValue = rawValue * 4095;               // Convert to 12-bit ADC value

            sprintf(buffer, "Light Value: %d\n", lightValue);
            sendSerialMessage(buffer);

            led = (lightValue < LIGHT_THRESHOLD) ? 1 : 0;
        } else {
            led = 0;
        }

        ThisThread::sleep_for(1s);  // Adjust this interval to your needs
    }
}
*/