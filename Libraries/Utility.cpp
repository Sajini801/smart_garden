#include "Utility.h"
#include <stdio.h>

// Function to format float values (to 2 decimal places)
void formatFloat(float value, char* buffer) {
    int intPart = (int)value;
    int fracPart = (int)((value - intPart) * 100);  // Multiply fractional part by 100 for 2 decimals
    snprintf(buffer, 64, "%d.%02d", intPart, fracPart);  // Format as int.int
}
