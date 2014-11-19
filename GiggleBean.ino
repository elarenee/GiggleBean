#include <CapacitiveSensor.h>
#include "dj.h"
#include "lightcombo.h"
#include "target.h"
#include "ledcontroller.h"
#include "speaker.h"
#include "track.h"
#include "textilesensor.h"
 

int main() {
 
  // specifying which pins map to which targets on textile
  CapacitiveSensor   cs_3_2 = CapacitiveSensor(3,2);
  CapacitiveSensor   cs_24_26 = CapacitiveSensor(24,26); 
  CapacitiveSensor   cs_8_9 = CapacitiveSensor(8,9); 
  
  cs_3_2.set_CS_AutocaL_Millis(0xFFFFFFFF);     // turn off autocalibrate on channel 1 - just as an example
  cs_24_26.set_CS_AutocaL_Millis(0xFFFFFFFF);
  cs_8_9.set_CS_AutocaL_Millis(0xFFFFFFFF);

  int ledPinB = 8;                                 //Blue LED
  int ledPinG = 12;                                //Green LED
  int ledPinR = 11;                                //Red LED 

  pinMode(ledPinB, OUTPUT);
  pinMode(ledPinG, OUTPUT);
  pinMode(ledPinR, OUTPUT);

  Serial.begin(9600);

  TextileSensor textile;
  DJ dj;
  LEDController leds;

  bool songEnded = false;

  while(true) {

    textile.updateTargetArray();  
    dj.speaker.updateSongs(songEnded); 

    if(textile.allBlinkingTargetsTouched(leds.getCurBlinkCombo())) {
      if(dj.speaker.songPlaying() ) {
        //adjust volume
        dj.adjustVolume(leds.getCurBlinkCombo());
      }
      else {
        leds.stopBlinking();
        dj.determineSong(leds.getCurBlinkCombo(), textile.targets);
      } 
    }
    // may or may not play a sound depending on whether the textile is being touched somewhere
    else {
      dj.determineSound(leds.getCurBlinkCombo());
    
    } 
    
    if(songEnded) {
      leds.shuffleBlinkingLEDs();
      songEnded = false;
    } 
    
  }

  return 0;

}