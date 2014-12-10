#include "ledcontroller.h"
#include "lightcombo.h"
#include "textilesensor.h"
#include <stdlib.h>

// LIGHT COMBOS: (hard-coded)
// Blue Targets
//    0 (ara height)
//    1 (ara height)
//    2 (dad height)
// Red Targets
//    3 (ara height)
//    4 (ara height)
//    5 (dad height)
// Yellow Targets
//    6 (ara height)
//    7 (dad height)

LEDController::LEDController() {
    //constructor
    // Hard-coded array of possible combinations of targets that can be blinking simultaneously. 
    // We have to hard-code these values because we only want LEDs that are of the same color to be blinking at the same time. NOT complete yet
    
    lightCombos[0] = LightCombo(0,1,BLUE);     //2
    lightCombos[1] = LightCombo(1,2,BLUE);     //2
    lightCombos[2] = LightCombo(0,2,BLUE);     //2
    lightCombos[3] = LightCombo(2,-1,BLUE);    //Dad only
    lightCombos[4] = LightCombo(3,4,RED);      //2
    lightCombos[5] = LightCombo(4,5,RED);      //2
    lightCombos[6] = LightCombo(3,5,RED);      //2
    lightCombos[7] = LightCombo(5,-1,RED);     //Dad only
    lightCombos[8] = LightCombo(6,7,YELLOW);   //2
    lightCombos[9] = LightCombo(7,-1,YELLOW);  //Dad only


    shuffleBlinkingLEDs();
                              
}

void LEDController::turnLightsOff() {

  digitalWrite(ledPinB1, LOW);
  digitalWrite(ledPinB2, LOW);
  digitalWrite(ledPinB3, LOW);
  digitalWrite(ledPinR1, LOW);
  digitalWrite(ledPinR2, LOW);
  digitalWrite(ledPinR3, LOW);
  digitalWrite(ledPinY1, LOW);
  digitalWrite(ledPinY2, LOW);

}

void LEDController::stopBlinking() {
  // make all LEDs steady (no blinking/pulsing anywhere)
  if (lightModeOn){
    digitalWrite(ledPinB1, HIGH);
    digitalWrite(ledPinB2, HIGH);
    digitalWrite(ledPinB3, HIGH);
    digitalWrite(ledPinR1, HIGH);
    digitalWrite(ledPinR2, HIGH);
    digitalWrite(ledPinR3, HIGH);
    digitalWrite(ledPinY1, HIGH);
    digitalWrite(ledPinY2, HIGH);
  } else {
    turnLightsOff();
  }

}

void LEDController::shuffleBlinkingLEDs() {
  
  int rand_idx = rand() % 10;
  LightCombo rand_combo = lightCombos[rand_idx];
  currentBlinkCombo = LightCombo(rand_combo);
}


void LEDController::makeBlink() {
  // make the specified target region blink (needs to access the targets[] array within TextileSensor)
  // directly modify the pin associated with that target (ask Matt)
  if (lightModeOn) {
    digitalWrite(TextileSensor().targets[currentBlinkCombo.target1Index].ledPin, LOW);
    if (currentBlinkCombo.target2Index != -1) {
      digitalWrite(TextileSensor().targets[currentBlinkCombo.target2Index].ledPin, LOW);
    } 
    delay(100);

    digitalWrite(TextileSensor().targets[currentBlinkCombo.target1Index].ledPin, HIGH);
    if (currentBlinkCombo.target2Index != -1) {
      digitalWrite(TextileSensor().targets[currentBlinkCombo.target2Index].ledPin, HIGH);
    } 
    delay(100); 
  }
  else {
    delay(200);
  }
}

void LEDController::makeWholeBeanBlink() {
    turnLightsOff();
    delay(300);
    stopBlinking(); 
    delay(300);
}

LightCombo LEDController::getCurBlinkCombo() {
	return currentBlinkCombo;
}
