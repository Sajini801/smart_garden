/* #include "mbed.h"
#include "SerialCom.h"
#include "RTC.h"

RTC_HandleTypeDef hrtc;  // Define RTC handler

void initializeRTC() {
    sendSerialMessage("Initializing RTC...\n");

    // Enable the required RTC peripheral clocks and power
    __HAL_RCC_PWR_CLK_ENABLE();
    HAL_PWR_EnableBkUpAccess();
    __HAL_RCC_RTC_ENABLE();

    // Set RTC time - make sure the RTC peripheral is enabled and clocks are set
    RTC_TimeTypeDef sTime = {0};
    RTC_DateTypeDef sDate = {0};

    sTime.Hours = 12;  // Set a default time
    sTime.Minutes = 0;
    sTime.Seconds = 0;
    if (HAL_RTC_SetTime(&hrtc, &sTime, RTC_FORMAT_BIN) != HAL_OK) {
        sendSerialMessage("Failed to set RTC Time!\n");
        while (1);  // Halt if there’s an error
    }

    sDate.WeekDay = RTC_WEEKDAY_MONDAY;
    sDate.Month = RTC_MONTH_JANUARY;
    sDate.Date = 1;
    sDate.Year = 22;  // Set default date
    if (HAL_RTC_SetDate(&hrtc, &sDate, RTC_FORMAT_BIN) != HAL_OK) {
        sendSerialMessage("Failed to set RTC Date!\n");
        while (1);  // Halt if there’s an error
    }

    sendSerialMessage("RTC Initialized.\n");
}

void printRTCtime() {
    RTC_TimeTypeDef sTime;
    RTC_DateTypeDef sDate;

    if (HAL_RTC_GetTime(&hrtc, &sTime, RTC_FORMAT_BIN) != HAL_OK) {
        sendSerialMessage("Failed to get RTC time!\n");
        return;
    }

    if (HAL_RTC_GetDate(&hrtc, &sDate, RTC_FORMAT_BIN) != HAL_OK) {
        sendSerialMessage("Failed to get RTC date!\n");
        return;
    }

    char timeStr[64];
    snprintf(timeStr, sizeof(timeStr), "Time: %02d:%02d:%02d\n", sTime.Hours, sTime.Minutes, sTime.Seconds);
    sendSerialMessage(timeStr);  // Send the time over serial
}

int main() {
    sendSerialMessage("Starting RTC Example...\n");

    // Initialize RTC
    initializeRTC();

    // Main loop
    while (true) {
        printRTCtime();  // Print current RTC time
        ThisThread::sleep_for(1000ms);  // Wait for 1 second before printing again
    }
}
*/