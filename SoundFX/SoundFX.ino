#include <PCM.h>
#include <Bounce2.h>
#include "wav.h"

#define inputPin 1

Bounce  bouncer  = Bounce(); 

void setup() {
  // put your setup code here, to run once:
  pinMode( inputPin ,INPUT);
  digitalWrite( inputPin ,HIGH);

  bouncer .attach( inputPin );
  bouncer .interval(5);
  
}

void loop() {
  bouncer.update();
  if( bouncer.fell() ){
    startPlayback(Laser8khz_wav, Laser8khz_wav_len);
  }
}
