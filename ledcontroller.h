#ifndef LEDCONTROLLER_H
#define LEDCONTROLLER_H

#include "lightcombo.h"

class LEDController {

public:
  //attr:
  LightCombo currentBlinkCombo; // this is the current combination of targets that are currently blinking on the bean. it is set and reset by this class’s shuffleBlink() method
  bool lightModeOn;
// LIGHT COMBOS: (hard-coded)
// Blue Targets
//    0 (ara height)
//    1 (ara height)
//    2 (dad height)
// Red Targets
//    3 (ara height)
//    4 (ara height)
//    5 (dad height)
// Green Targets
//    6 (ara height)
//    7 (dad height)

  LightCombo lightCombos[10]; // this is the hard-coded array of possible combinations of targets that can be blinking simultaneously.
  // We have to hard-code these values because we only want LEDs that are of the same color to be blinking at the same time.
  // Values initialized in the constructor. 

  //methods:
  LEDController();
  void turnLightsOff();
  void stopBlinking();  
  void shuffleBlinkingLEDs();
  void makeBlink();
  void makeWholeBeanBlink(); //Use this when the Bluetooth is resetting

  LightCombo getCurBlinkCombo();
  friend class  TextileSensor;
};

#endif

