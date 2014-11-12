#include "ledcontroller.h"
#include "lightcombo.h"

//methods:
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
