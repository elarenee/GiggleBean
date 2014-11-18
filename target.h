#ifndef TARGET_H
#define TARGET_H


struct Target {

  Target(int outPNum, int inPNum)) 
	: outPinNum(outPNum), inPinNum(inPNum), pressureReading(0), touched(false) {}
  //attr:
  int ledPin; // this is the pin number associated with LED output
  int capSensPin; // this is the pin number associated with this target region’s analog sensor reading
  double pressureReading; // value retrieved from pin# inPinNum
  bool touched;
  Track sounds[2];
  
};


#endif

