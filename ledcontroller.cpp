#include "ledcontroller.h"
#include "lightcombo.h"
#include "textilesensor.h"
#include <stdlib.h>

// LIGHT COMBOS: (hard-coded)
// Blue Targets
//    0 (ara height)
//    1 (ara height)
//    5 (dad height)
// Red Targets
//    2 (ara height)
//    3 (ara height)
//    7 (dad height)
// Yellow Targets
//    4 (ara height)
//    6 (dad height)

LEDController::LEDController() {
    //constructor
    // Hard-coded array of possible combinations of targets that can be blinking simultaneously. 
    // We have to hard-code these values because we only want LEDs that are of the same color to be blinking at the same time. NOT complete yet
    
    lightCombos[0] = LightCombo(0,1,BLUE); 
    lightCombos[1] = LightCombo(1,5,BLUE);
    lightCombos[2] = LightCombo(0,5,BLUE);
    lightCombos[3] = LightCombo(0,-1,BLUE);
    lightCombos[4] = LightCombo(1,-1,BLUE);
    lightCombos[5] = LightCombo(5,-1,BLUE);
    lightCombos[6] = LightCombo(2,3,RED);
    lightCombos[7] = LightCombo(3,7,RED);
    lightCombos[8] = LightCombo(2,7,RED);
    lightCombos[9] = LightCombo(2,-1,RED);
    lightCombos[10] = LightCombo(3,-1,RED);
    lightCombos[11] = LightCombo(7,-1,RED);
    lightCombos[12] = LightCombo(4,6,YELLOW);
    lightCombos[13] = LightCombo(4,-1,YELLOW);
    lightCombos[14] = LightCombo(6,-1,YELLOW);

    currentBlinkCombo = lightCombos[0];
    //shuffleBlinkingLEDs();
                                
}

void LEDController::stopBlinking() {
  // make all LEDs steady (no blinking/pulsing anywhere) (directly modifying pin output...ask Matt)
  digitalWrite(ledPinB1, HIGH);
  digitalWrite(ledPinB2, HIGH);
  digitalWrite(ledPinB2, HIGH);
  digitalWrite(ledPinR1, HIGH);
  digitalWrite(ledPinR2, HIGH);
  digitalWrite(ledPinR3, HIGH);
  digitalWrite(ledPinY1, HIGH);
  digitalWrite(ledPinY2, HIGH);
}

void LEDController::shuffleBlinkingLEDs() {
  
  int rand_idx = rand() % 14;
  LightCombo rand_combo = lightCombos[0];
  currentBlinkCombo = LightCombo(rand_combo);
}

void LEDController::makeBlink(int index) {
  // make the specified target region blink (needs to access the targets[] array within TextileSensor)
  // directly modify the pin associated with that target (ask Matt)
  
  digitalWrite(TextileSensor().targets[index].ledPin, HIGH);
  delay(100);
  digitalWrite(TextileSensor().targets[index].ledPin, LOW);
  delay(100); 
}

LightCombo LEDController::getCurBlinkCombo() {
	return currentBlinkCombo;
}
