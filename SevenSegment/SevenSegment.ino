#include "SevSeg.h"

SevSeg sevseg;

void setup() {
  byte numDigits = 4;
  byte digitPins[] = {2,3,4,5};
  byte segmentPins[] = {6,7,8,9,10,16,14,15};
  sevseg.begin(COMMON_ANODE, numDigits, digitPins, segmentPins);
}

void loop() {
  sevseg.setNumber(1234,-1);
  sevseg.refreshDisplay();
}
