#ifndef TEXTILESENSOR_H
#define TEXTILESENSOR_H

#include "target.h"
#include "lightcombo.h"

class TextileSensor { // this class should be friends with LEDController

friend class DJ;

  //attr:
  Target targets[8]; 
  
protected:
  //methods:
  void updateTargetArray();
  	// this should update the values within the targets array based upon the data coming from the Arduino input pins
  
  bool allBlinkingTargetsTouched(LightCombo currBlinkCombo);

};

#endif


