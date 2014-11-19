#include <CapacitiveSensor.h>
#include "dj.h"
#include "lightcombo.h"
#include "target.h"
#include "ledcontroller.h"
#include "speaker.h"
#include "track.h"
#include "textilesensor.h"
 

  // specifying which pins map to which targets on textile
  CapacitiveSensor   cs_3_2 = CapacitiveSensor(3,2);
  CapacitiveSensor   cs_24_26 = CapacitiveSensor(24,26); 
  CapacitiveSensor   cs_8_9 = CapacitiveSensor(8,9); 
  

   
  void setup() {
    // put your setup code here, to run once:
    

    Serial.begin(9600);
    pinMode(ledPinB1, OUTPUT);
    pinMode(ledPinB2, OUTPUT);
    pinMode(ledPinB3, OUTPUT);
    pinMode(ledPinR1, OUTPUT);
    pinMode(ledPinR2, OUTPUT);
    pinMode(ledPinR3, OUTPUT);
    pinMode(ledPinY1, OUTPUT);
    pinMode(ledPinY2, OUTPUT);

    pinMode(touchPinB1, INPUT);
    pinMode(touchPinB2, INPUT);
    pinMode(touchPinB3, INPUT);
    pinMode(touchPinR1, INPUT);
    pinMode(touchPinR2, INPUT);
    pinMode(touchPinR3, INPUT);
    pinMode(touchPinY1, INPUT);
    pinMode(touchPinY2, INPUT);
    
  
  
  }
  
  bool songEnded = false;
  TextileSensor textile;
  DJ dj;
  LEDController leds;

  void loop() {
    textile.updateTargetArray();  
    dj.speaker.updateSongs(songEnded); 

    if(textile.allBlinkingTargetsTouched(leds.getCurBlinkCombo())) {
      if(dj.speaker.songPlaying() ) {
        //adjust volume
        dj.adjustVolume(leds.getCurBlinkCombo(), textile.targets);
      }
      else {
        leds.stopBlinking();
        dj.determineSong(leds.getCurBlinkCombo(), textile.targets);
      } 
    }
    // may or may not play a sound depending on whether the textile is being touched somewhere
    else {
      dj.determineSound(textile.targets);
    
    } 
    
    if(songEnded) {
      leds.shuffleBlinkingLEDs();
      songEnded = false;
    } 
    
  }