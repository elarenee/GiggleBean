#ifndef LEDCONTROLLER_H
#define LEDCONTROLLER_H

#include "lightcombo.h"

class LEDController {

  //attr:
  LightCombo currentBlinkCombo; // this is the current combination of targets that are currently blinking on the bean. it is set and reset by this class’s shuffleBlink() method
  
  LightCombo lightCombos[15]; // this is the hard-coded array of possible combinations of targets that can be blinking simultaneously. We have to hard-code these values because we only want LEDs that are of the same color to be blinking at the same time. 
  
  //methods:
  LEDController();
  void stopBlinking();  
  void shuffleBlinkingLEDs();
  void makeBlink(int index);
  LightCombo getCurBlinkCombo();

};

#endif

