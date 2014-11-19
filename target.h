#ifndef TARGET_H
#define TARGET_H

#include "track.h"

struct Target {

  Target()
  	: ledPin(0), capSensPin(0), pressureReading(0), touched(false) {}
  Target(int inLedPin, int inCapSensPin) 
	: ledPin(inLedPin), capSensPin(inCapSensPin), pressureReading(0), touched(false) {}
  //attr:
  int ledPin; // this is the pin number associated with LED output
  int capSensPin; // this is the pin number associated with this target region’s analog sensor reading
  double pressureReading; // value retrieved from pin# inPinNum
  bool touched;
  Track sounds[2];
  
};


#endif

