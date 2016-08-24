#include <elapsedMillis.h>
#include <LedControl.h>
#include <Bounce2.h>

int counter = 0;
bool isbullet=false;
bool wasbullet=false;

Bounce addAmmoButton = Bounce();
Bounce lightButton = Bounce();
byte numDigits = 2;

LedControl lc1=LedControl(12,11,10,numDigits);

void setup() {
  pinMode(13,OUTPUT);
  pinMode(2,INPUT_PULLUP);
  pinMode(3,INPUT_PULLUP);
  digitalWrite(13, LOW );

  lc1.shutdown(0,false);
  lc1.setIntensity(0,8);
  lightButton.attach( 3 );
  lightButton.interval( 5 );
  addAmmoButton.attach( 2 );
  addAmmoButton.interval( 5 );
  
  displayNumber(counter);
}

void loop() {
  addAmmoButton.update();
  lightButton.update();
  
  if( lightButton.rose() ){
    digitalWrite(13, !digitalRead(13) );
  }
  
  if( addAmmoButton.fell() ){
    counter++;
    displayNumber(counter);
  } 

  if(analogRead(A0)<400){
    isbullet=true; 
  }

  if(isbullet<wasbullet){
    counter--;
    displayNumber(counter);
  }

  wasbullet=isbullet;  
}

void displayNumber(int value) {
  byte tens = ( value / 10 ) % 10;
  byte ones = value % 10;
  
  lc1.setDigit(0,0,tens,false);
  lc1.setDigit(0,1,ones,false);
}