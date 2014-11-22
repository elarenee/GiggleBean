
#ifndef TARGET_H
#define TARGET_H

#include "track.h"
#include <CapacitiveSensor.h>


struct Target {

  Target()
  	: ledPin(0), analogPin(0), capSensPin(0,0), resistanceReading(0), touched(false) {}
  Target(int inLedPin, int inAnalogPin, CapacitiveSensor inCapSensPin) 
	: ledPin(inLedPin), analogPin(inAnalogPin), capSensPin(inCapSensPin), resistanceReading(0), touched(false) {}
  //attr:
  int ledPin; // this is the pin number associated with LED output
  int analogPin; // this is the pin number associated with this target region’s analog sensor reading
  CapacitiveSensor capSensPin; // 2 pins for cap sens touch reading (digital), initialized in GiggleBean.ino
  float resistanceReading; // value retrieved from pin# inPinNum
  bool touched;
  bool stretched;
  Track sounds[2];
  
};


#endif

