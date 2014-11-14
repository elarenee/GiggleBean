#include <CapacitiveSensor.h>
#include "dj.h"
#include "lightcombo.h"
#include "target.h"
 
  // specifying which pins map to which targets on textile
  CapacitiveSensor   cs_3_2 = CapacitiveSensor(3,2);
  CapacitiveSensor   cs_24_26 = CapacitiveSensor(24,26); 
  CapacitiveSensor   cs_8_9 = CapacitiveSensor(8,9); 
  
  int ledPinB = 8;                                 //Blue LED
  int ledPinG = 12;                                //Green LED
  int ledPinR = 11;                                //Red LED
   
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
  
  void loop() {
    textile.updateTargetArray(); // read data from input pins on Arduino
    dj.speaker.updateSounds(); // given Target array
    dj.speaker.updateSongs(); 

    if(textile.allBlinkingTargetsTouched(leds.getCurBlinkCombo())) {
      if(!dj.speaker.songPlaying() ) {
        leds.stopBlinking();
        dj.determineSong(leds.getCurBlinkCombo());
        // get the target1index from the LightCombo passed into the function. 
        // then get the color and pressure reading from TextileSensor class 
        // (which owns the target array) … 
        // maybe DJ and TextileSensor should be friends...
        
        // and then start playing the new song
      
      }
      else {
        //adjust volume
      }
      
      
    }
    dj.determineSound(); // may or may not play a sound depending on whether the textile is being touched somewhere
    if(songEnded) {
      leds.shuffleBlinkingLEDs();
    } 
    
  }
  

