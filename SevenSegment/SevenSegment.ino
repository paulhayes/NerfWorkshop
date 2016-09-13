#include "SevSeg.h"
#include <elapsedMillis.h>

SevSeg sevseg;
int counter = 1000;
elapsedMillis timeElapsed;

void setup() {
  byte numDigits = 4;
  byte digitPins[] = {2,3,4,5};
  byte segmentPins[] = {6,7,8,9,10,16,14,15};
  sevseg.begin(COMMON_ANODE, numDigits, digitPins, segmentPins);
}

void loop() {
  sevseg.setNumber(counter,0);
  sevseg.refreshDisplay();
  if( timeElapsed >= 1000 ){
    timeElapsed = 0;
    counter--;

  }
      
}
