#include <CapacitiveSensor.h>
#include "dj.h"
#include "lightcombo.h"
#include "target.h"
#include "ledcontroller.h"
#include "speaker.h"
#include "track.h"
#include "textilesensor.h"
 
  bool songEnded = false;
  TextileSensor textile;
  DJ dj;
  LEDController leds;
   
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

    pinMode(analogPinB1, INPUT);
    pinMode(analogPinB2, INPUT);
    pinMode(analogPinB3, INPUT);
    pinMode(analogPinR1, INPUT);
    pinMode(analogPinR2, INPUT);
    pinMode(analogPinR3, INPUT);
    pinMode(analogPinY1, INPUT);
    pinMode(analogPinY2, INPUT);
    
  }
  
  

  void loop() {
    textile.updateTargetArray(); 
    leds.makeBlink(leds.getCurBlinkCombo().target1Index);
    //dj.speaker.updateSongs(songEnded); 
      
    if(textile.allBlinkingTargetsTouched(leds.getCurBlinkCombo())) {
//      if(dj.speaker.songPlaying() ) {
//        //adjust volume
//        dj.adjustVolume(leds.getCurBlinkCombo(), textile.targets);
//      }
//      else {
        leds.stopBlinking();
//        dj.determineSong(leds.getCurBlinkCombo(), textile.targets);
//      } 
    }
    
//    // may or may not play a sound depending on whether the textile is being touched somewhere
//    else {
//      dj.determineSound(textile.targets);
//    
//    } 
//    
//    if(songEnded) {
//      leds.shuffleBlinkingLEDs();
//      songEnded = false;
//    } 
    
  }
