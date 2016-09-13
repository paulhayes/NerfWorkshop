#include "SevSeg.h"
#include <elapsedMillis.h>
#include <Bounce2.h>

SevSeg sevseg;

int counter = 0;
bool isbullet=false;
bool wasbullet=false;
int printInterval = 500;
Bounce addAmmoButton = Bounce();

elapsedMillis timeElapsed; 

void setup() {
  Serial.begin(9600);
  byte numDigits = 2;
  pinMode(2,INPUT_PULLUP);
  addAmmoButton.attach( 2 );
  addAmmoButton.interval( 5 );


  byte digitPins[] = {12,11};
  byte segmentPins[] = {10,9,8,7,6,5,4,3};
  sevseg.begin(COMMON_ANODE, numDigits, digitPins, segmentPins);

  sevseg.setBrightness(20);
}

void loop() {
  
  addAmmoButton.update();
  if( addAmmoButton.fell() ){
    counter++;
  } 
  isbullet = false;
  int v = analogRead(A7);

  if( timeElapsed >= printInterval ){
    Serial.println(v);
  }

  
  if(v<600){
    isbullet=true; 
  }
  if(!isbullet && wasbullet){
    counter--;
  }
  sevseg.setNumber(counter,0);
  sevseg.refreshDisplay();
  wasbullet = isbullet;
}
