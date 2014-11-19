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
    TextileSensor textile;
    DJ dj;
    LEDController leds;
    cs_3_2.set_CS_AutocaL_Millis(0xFFFFFFFF);     // turn off autocalibrate on channel 1 - just as an example
    cs_24_26.set_CS_AutocaL_Millis(0xFFFFFFFF);
    cs_8_9.set_CS_AutocaL_Millis(0xFFFFFFFF);
    Serial.begin(9600);
    pinMode(ledPinB, OUTPUT);
    pinMode(ledPinG, OUTPUT);
    pinMode(ledPinR, OUTPUT);
  
  
  }
  
bool songEnded = false;

  void loop() {
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