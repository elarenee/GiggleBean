struct Target {

  //attr:
  int outPinNum; // this is the pin number associated with LED output
  int inPinNum; // this is the pin number associated with this target region’s analog sensor reading
  double pressureReading; // value retrieved from pin# inPinNum
  bool touched;

};


class TextileSensor { // this class should be friends with LEDController

  //attr:
  Target targets[8]; 
  
  //methods:
  void updateTargetArray() {
  	// this should update the 
  }
  bool allBlinkingTargetsTouched(LightCombo currBlinkCombo) {
  	
  }

};


