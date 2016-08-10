#include <PCM.h>
#include <Bounce2.h>
#include "wav.h"

#define inputPin 1
#define speakerPin 11

Bounce  bouncer  = Bounce(); 

void setup() {
  pinMode( inputPin ,INPUT);
  digitalWrite( inputPin ,HIGH);

  bouncer.attach( inputPin );
  bouncer.interval(5);
  
}

void loop() {
  bouncer.update();
  if( bouncer.fell() ){
    stopPlayback();
    startPlayback(Laser8khz_wav, Laser8khz_wav_len);
  }
}
