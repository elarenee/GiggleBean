
#ifndef TARGET_H
#define TARGET_H

#include "track.h"
#include <CapacitiveSensor.h>

static const int defaultHighResInterval = 45;
static const int defaultLowResInterval = 60;

//we store the past N values for resistance reading
//once this is full, we do some logic
//then we start over at the beginning of the array
static const int sizeMemArray = 10;
static int memArrayIndex = 0;

struct Target {

  Target()
  	: ledPin(0), analogPin(0), lowResInterval(defaultLowResInterval),
          highResInterval(defaultHighResInterval), touched(false), stretched(false), baselineRes(0), cyclesSinceRelease(0),
          cyclesStretched(0), cyclesTouched(0) {}
  Target(int inLedPin, int inAnalogPin, int inLowRes, int inHighRes) 
	: ledPin(inLedPin), analogPin(inAnalogPin), lowResInterval(inLowRes),
          highResInterval(inHighRes), touched(false), stretched(false), baselineRes(0), cyclesSinceRelease(0),
          cyclesStretched(0), cyclesTouched(0) {}

  //attr:
  int ledPin; // this is the pin number associated with LED output
  int analogPin; // this is the pin number associated with this target region’s analog sensor reading
  int baselineRes; // value retrieved from analog read
  int lowResInterval; //when softly touched, the resistance drops suddenly for about one loop. 
                        //through testing we will hard code a value just above where it drops to on a soft touch.
  int highResInterval; //when pushed hard, the resistance rises suddenly for the duration of the push. 
                        //through testing we will hard code a value just below the resistance for "hard pressure."
  int resistanceReadings[sizeMemArray];
  bool touched;
  bool stretched;
  int cyclesSinceRelease; //we'll track how many loops we've gone through since the target stopped being
                          // stretched or touched. after N loops we'll recalibrate.

  int cyclesStretched;
  int cyclesTouched; 
  //Track sounds[2];
  
};


#endif

