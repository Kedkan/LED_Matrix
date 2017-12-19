#ifndef LED_8X8_h
#define LED_8X8_h

#include "Arduino.h"

#define latchPin 6 		// LT
#define clockPin 7		// CLK
#define dataPin 8  		// MOSI

void lightStaticLED(int tempLED[8][8]);
void lightLED();
void scrollLED(int oneSkrollLEd[8][8], int twoSkrollLED[8][8]);

#endif 			// LED_8X8_h
