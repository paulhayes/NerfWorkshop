#include <stdint.h>
#include <avr/interrupt.h>
#include <avr/io.h>
#include <avr/pgmspace.h>
#include <Bounce2.h>
#include "PCM2.h"
#include "wav.h"

#define SAMPLE_RATE 8000

#define inputPin 1

int ledPin = 13;
int speakerPin = 11; // Can be either 3 or 11, two PWM outputs connected to Timer 2
volatile uint16_t sample;
byte lastSample;

Bounce  bouncer  = Bounce(); 

void setup() {
  // put your setup code here, to run once:
  pinMode( inputPin ,INPUT);
  digitalWrite( inputPin ,HIGH);

  bouncer.attach( inputPin );
  bouncer.interval(5);
  
}

void loop() {
  bouncer.update();
  if( bouncer.fell() ){
    startPlayback(Laser8khz_wav, Laser8khz_wav_len);
  }
}


