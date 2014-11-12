#ifndef TARGET_H
#define TARGET_H


struct Target {

  //attr:
  int outPinNum; // this is the pin number associated with LED output
  int inPinNum; // this is the pin number associated with this target region’s analog sensor reading
  double pressureReading; // value retrieved from pin# inPinNum
  bool touched;

};

#endif

