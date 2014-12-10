#include "dj.h"
#include "lightcombo.h"
#include "target.h"
#include "ledcontroller.h"
//#include "speaker.h"
//#include "track.h"
#include "textilesensor.h"

 

  int loopsLeftToCalibrate = 10;
  const int totalLoopsToCalibrate = 10;
  bool bluetoothResetting = false;

  bool songJustEnded = false;

  TextileSensor textile;
  DJ dj;
  LEDController leds;

  char serialMessage[4];
  char inputChar;
  int index = 0;
  
  
  void setup() {
    // put your setup code here, to run once:
    dj.soundModeOn = true;
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
  }
  
  

  void loop() {
    //Get Messages from Android
    if (Serial.available()){
      Serial.print(Serial.read());
      for (int i = 0;i < 3;i++){
        inputChar = Serial.read();
        serialMessage[i] = inputChar;
        serialMessage[i+1] = '\0';
      }
      if (!strcmp(serialMessage, "000")){ //Lights ON/OFF Pressed
        leds.lightModeOn = !leds.lightModeOn;
        memset(serialMessage, -1, sizeof(serialMessage));
        index = 0;
      } 
      else if (!strcmp(serialMessage, "111")){ //Sound ON/OFF Pressed
        dj.soundModeOn = !dj.soundModeOn;
        memset(serialMessage, -1, sizeof(serialMessage));
        index = 0;
      }
      else if (!strcmp(serialMessage, "212")){ //OnComplete for Any Song Ending
        //if the song has just ended, we just shuffle and blink
        Serial.println("test");
        songJustEnded = true;
        dj.songIsPlaying = false;
        memset(serialMessage, -1, sizeof(serialMessage));
        index = 0;
      }
      else if (!strcmp(serialMessage, "001")){ //Restarting BlueTooth
        //Let's slowly blink all lights so the bean seems inactive but still on
        bluetoothResetting = true;
        leds.makeWholeBeanBlink();
        memset(serialMessage, -1, sizeof(serialMessage));
        index = 0;
      }
      else if (!strcmp(serialMessage, "002")){ //BlueTooth Successfully Restarted
        //Get back to playing
        bluetoothResetting = false;
        leds.makeBlink();
        memset(serialMessage, -1, sizeof(serialMessage));
        index = 0;
      }
      else if (!strcmp(serialMessage, "555")){ //App Turned Off
        //TODO what goes here?
        memset(serialMessage, -1, sizeof(serialMessage));
        index = 0;
      }
//      if (!strcmp(serialMessage, "132")){ //Currently not implemented
//      delay(5000);
//        Serial.println("Re-Calibrate");
//        memset(serialMessage, -1, sizeof(serialMessage));
//        index = 0;
//        loopsLeftToCalibrate = totalLoopsToCalibrate;
//        leds.turnLightsOff();
//      }
    } 
    else {
      index = 0;
    }
    //Check touches and send messages to Android
    if (textile.calibrated(loopsLeftToCalibrate, totalLoopsToCalibrate)) {
      //Tell the Android we are good to go
      //Do this every time in case one gets lost
      //PUT THIS BACK REMOVED FOR TESTING
      //Serial.println("012");

//take out for testing
     /* if (bluetoothResetting) {
        leds.makeWholeBeanBlink();
      }
      else */if (songJustEnded) {
        //in this case, we want to act on what's happening, then shuffle
        //so we don't get any accidental songs playing
        
        songJustEnded = false;
        dj.determineSound(textile.targets);
        leds.shuffleBlinkingLEDs();
        leds.makeBlink();
      }
      else {
        leds.stopBlinking();
        textile.updateTargetArray();
   
        //Check Song. If not Song check Sound.
        if(textile.allBlinkingTargetsStretched(leds.getCurBlinkCombo())) {
          if(!dj.songIsPlaying) {
            // Play Song
            if (!leds.lightModeOn) {
              Serial.println("leds on");
              //if lights aren't on, triggering a song would be an accident
              songJustEnded = true; //this will make the lights shuffle on the next loop
            }
            else {
              dj.determineSong(leds.getCurBlinkCombo());
              dj.songIsPlaying = true;
              leds.stopBlinking();
           //   Serial.println("all blinking targets stretched");
            }
          }
        }
        // Check Sound.
        else {
          dj.determineSound(textile.targets);
          if(!dj.songIsPlaying) 
            leds.makeBlink();  
        } 
        //delay(5000);
      }
    }
  }
    
  
