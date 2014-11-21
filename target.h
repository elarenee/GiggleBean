#ifndef TARGET_H
#define TARGET_H

#include "track.h"

struct Target {

  Target()
  	: ledPin(0), analogPin(0), capSensPin1(0), capSensPin2(0), resistanceReading(0), touched(false) {}
  Target(int inLedPin, int inAnalogPin, int inCapSensPin1, int inCapSensPin2) 
	: ledPin(inLedPin), analogPin(inAnalogPin), capSensPin1(inCapSensPin1), capSensPin2(inCapSensPin2), resistanceReading(0), touched(false) {}
  //attr:
  int ledPin; // this is the pin number associated with LED output
  int analogPin; // this is the pin number associated with this target region’s analog sensor reading
  int capSensPin1; // 2 pins for cap sens touch reading (digital)
  int capSensPin2; 
  double resistanceReading; // value retrieved from pin# inPinNum
  bool touched;
  bool stretched;
  Track sounds[2];
  
};


#endif

