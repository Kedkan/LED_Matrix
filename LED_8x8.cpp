#include "LED_8X8.h"
#include "Arduino.h"

int movement = 0;
int counter = 0;

int LED_template[8][17] = {   
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}      
};
void lightStaticLED( int tempLED[8][8] ) {
 byte columnBitsToSend = 0;
 byte rowBitsToSend = 0;
  int x = 0;
  int y = 0;
  
  for (x = 0; x < 8; x++) {
 columnBitsToSend = 0;
 rowBitsToSend = 0;
   for (y = 0; y < 8; y ++) {
      if (tempLED[x][y] == 1) {
        bitWrite(rowBitsToSend, y, HIGH);}
     }
    digitalWrite(latchPin, LOW);
    bitWrite(columnBitsToSend, x, HIGH);
    shiftOut(dataPin, clockPin, MSBFIRST, columnBitsToSend);
    shiftOut(dataPin, clockPin, MSBFIRST, rowBitsToSend);
    digitalWrite(latchPin, HIGH);   
    delay(2);}
}

void lightLED() {
  byte columnbitsToSend = 0;
  byte rowbitsToSend = 0;
  int x = 0;
  int y = 0;
  for (x = 0; x < 8; x++) {
    columnbitsToSend = 0;
    rowbitsToSend = 0;
    for (y = 0; y < 8; y ++) {
      if (LED_template[x][y] == 1) {
        bitWrite(rowbitsToSend, y, HIGH);}
    }
    digitalWrite(latchPin, LOW);
    bitWrite(columnbitsToSend, x, HIGH);
    shiftOut(dataPin, clockPin, MSBFIRST, columnbitsToSend);
    shiftOut(dataPin, clockPin, MSBFIRST, rowbitsToSend);
    digitalWrite(latchPin, HIGH);   
    delay(2);}}
void scrollLED(int oneSkrollLEd[8][8], int twoSkrollLED[8][8];{
  if (movement == 0) {
    int x;
    int y;
    for (x = 0; x < 8; x++) {
      for (y = 0; y < 8; y++) {
        LED_template[x][y+8] = oneSkrollLEd[x][y];} }
  } 
  if (movement == 8) {
    int x;
    int y;
    for (x = 0; x < 8; x++) {
      for (y = 0; y < 8; y++) {
        LED_template[x][y+8] = twoSkrollLED[x][y];} }
  } 
  if (counter % 25 == 0) {
    movement++;
    int x;
    int y;
    for (x = 0; x < 8; x++) {
      for (y = 0; y < 16; y++) {
        LED_template[x][y] = LED_template[x][y+1];} }
  }
  if (movement >= 16) {
    counter = 0;
    movement = 0;}
  lightLED();
  counter++;
}
