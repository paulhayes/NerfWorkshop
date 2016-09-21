#include "SevSeg.h"
#include <elapsedMillis.h>
#include <Bounce2.h>

SevSeg sevseg;

int lastV = 0;
int counter = 0;
bool isbullet=false;
bool wasbullet=false;
int printInterval = 500;
int deltaVThreshold = 50; // does the bullet cause a change in value above this between 2 samples?
int maxDeltaV = 0;
int minDeltaV = 0;
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
  int v = analogRead(A7);
  int deltaV = v - lastV;

  if( deltaV > maxDeltaV ){
    maxDeltaV = deltaV;
  }
  else if( deltaV < minDeltaV ){
    minDeltaV = deltaV;
  }
  

  if( timeElapsed >= printInterval ){
    Serial.print("v=")
    Serial.print(v);
    Serial.print(", maxDeltaV=");
    Serial.print(maxDeltaV);
    Serial.print(", minDeltaV=");
    Serial.println(minDeltaV);
    
    maxDeltaV = 0;
    minDeltaV = 0;
  }

  /* detect rising edge of bullet */
  if( deltaV > deltaVThreshold   ){
    isbullet=true; 
  }
  
  /* detect falling edge of bullet */
  if( -deltaV > deltaVThreshold  ){
    isbullet=false;
  }
  
  if(!isbullet && wasbullet){
    counter--;
  }
  sevseg.setNumber(counter,0);
  sevseg.refreshDisplay();
  wasbullet = isbullet;
  lastV = v;
}
