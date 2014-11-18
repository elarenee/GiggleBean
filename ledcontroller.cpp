#include "ledcontroller.h"
#include "lightcombo.h"

//methods:

// LIGHT COMBOS: (hard-coded)
// Blue Targets
//    0 (ara height)
//    1 (ara height)
//    5 (dad height)
// Red Targets
//    2 (ara height)
//    3 (ara height)
//    7 (dad height)
// Green Targets
//    4 (ara height)
//    6 (dad height)

/*LEDController::LEDController() {
    //constructor
    // Hard-coded array of possible combinations of targets that can be blinking simultaneously. 
    // We have to hard-code these values because we only want LEDs that are of the same color to be blinking at the same time. NOT complete yet
    lightCombos= {  LightCombo(0,1,Color.BLUE), 
                    LightCombo(1,5,Color.BLUE), 
                    LightCombo(0,5,Color.BLUE),
                    LightCombo(0,-1,Color.BLUE), 
                    LightCombo(1,-1,Color.BLUE), 
                    LightCombo(5,-1,Color.BLUE), 
                    LightCombo(2,3,Color.RED),
                    LightCombo(3,7,Color.RED), 
                    LightCombo(2,7,Color.RED), 
                    LightCombo(2,-1,Color.RED),
                    LightCombo(3,-1,Color.RED), 
                    LightCombo(7,-1,Color.RED), 
                    LightCombo(4,6,Color.GREEN), 
                    LightCombo(4,-1,Color.GREEN), 
                    LightCombo(6,-1,Color.GREEN), 
                  };
}*/

void LEDController::stopBlinking() {
  // make all LEDs steady (no blinking/pulsing anywhere) (directly modifying pin output...ask Matt)
  
}

void LEDController::shuffleBlinkingLEDs() {
  
  int rand_idx = rand() % 14;
  LightCombo rand_combo = this.lightCombos[rand_idx];
  this.currentBlinkCombo = new LightCombo(rand_combo);
  
}

void LEDController::makeBlink(int index) {
  // make the specified target region blink (needs to access the targets[] array within TextileSensor)
  // directly modify the pin associated with that target (ask Matt)
  
}

LightCombo LEDController::getCurBlinkCombo() {
	return this.currentBlinkCombo;
}
