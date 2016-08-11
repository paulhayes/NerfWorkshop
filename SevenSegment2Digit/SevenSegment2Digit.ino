#include "SevSeg.h"
#include <elapsedMillis.h>

SevSeg sevseg;
int counter = 99;
elapsedMillis timeElapsed;

void setup() {
  byte numDigits = 2;
  byte digitPins[] = {12,11};
  byte segmentPins[] = {10,9,8,7,6,5,4,3};
  sevseg.begin(COMMON_ANODE, numDigits, digitPins, segmentPins);
}

void loop() {
  sevseg.setNumber(counter,-1);
  sevseg.refreshDisplay();
  if( timeElapsed >= 1000 ){
    timeElapsed = 0;
    counter--;

  }
      
}
