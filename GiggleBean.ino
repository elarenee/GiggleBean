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
  char serialMessage[3];
  char inputChar;
  int index = 0;
  
  
  void setup() {
    // put your setup code here, to run once:
    leds.lightModeOn = true;
    
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
    
    pinMode(voltPinB1, OUTPUT);
    pinMode(voltPinB2, OUTPUT);
    pinMode(voltPinB3, OUTPUT);
    pinMode(voltPinR1, OUTPUT);
    pinMode(voltPinR2, OUTPUT);
    pinMode(voltPinR3, OUTPUT);  
    pinMode(voltPinY1, OUTPUT);
    pinMode(voltPinY2, OUTPUT); 
   
   //digital write needed for voltage pins?
  }
  
  
void loop() {
    if (Serial.available()){
      for (int i = 0;i < 3;i++){
        inputChar = Serial.read();
        serialMessage[i] = inputChar;
        serialMessage[i+1] = '\0';
      }
      if (!strcmp(serialMessage, "000")){
        leds.lightModeOn = !leds.lightModeOn;
        memset(serialMessage, -1, sizeof(serialMessage));
        index = 0;
      } 
    } else {
      index = 0;
    }
    
    leds.stopBlinking();
    textile.updateTargetArray(); 
    leds.makeBlink(leds.getCurBlinkCombo().target1Index, leds.getCurBlinkCombo().target2Index);
    dj.speaker.updateSounds();
    //dj.speaker.updateSongs(songEnded); 
      
    if(textile.allBlinkingTargetsStretched(leds.getCurBlinkCombo())) {
//      if(dj.speaker.songPlaying() ) {999

//        //adjust volume
//        dj.adjustVolume(leds.getCurBlinkCombo(), textile.targets);
//      }
//      else {
        leds.stopBlinking();
        delay(5000);
        leds.shuffleBlinkingLEDs();
        dj.determineSong(leds.getCurBlinkCombo(), textile.targets);
//      } 
    }
    
//    // may or may not play a sound depending on whether the textile is being touched somewhere
    else {
      dj.determineSound(textile.targets);
//    
    } 
//    
//    if(songEnded) {
//      leds.shuffleBlinkingLEDs();
//      songEnded = false;
//    } 
    
  }
  
