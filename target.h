
#ifndef TARGET_H
#define TARGET_H

#include "track.h"
#include <CapacitiveSensor.h>


struct Target {

  Target()
  	: ledPin(0), analogPin(0), resistanceReading(0), touched(false), stretched(false) {}
  Target(int inLedPin, int inAnalogPin, int inLowRes, int inHighRes) 
	: ledPin(inLedPin), analogPin(inAnalogPin), resistanceReading(0), lowResistance(inLowRes),
          highResistance(inHighRes), touched(false), stretched(false) {}
  //attr:
  int ledPin; // this is the pin number associated with LED output
  int analogPin; // this is the pin number associated with this target region’s analog sensor reading
  int resistanceReading; // value retrieved from analog read
  int lowResistance; //when softly touched, the resistance drops suddenly for about one loop. 
                        //through testing we will hard code a value just above where it drops to on a soft touch.
  int highResistance; //when pushed hard, the resistance rises suddenly for the duration of the push. 
                        //through testing we will hard code a value just below the resistance for "hard pressure."
  bool touched;
  bool stretched;
  Track sounds[2];
  
};


#endif

