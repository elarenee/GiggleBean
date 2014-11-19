#include "textilesensor.h"
 

TextileSensor::TextileSensor() {
	// Fill this in once we know the pin numbers for each target
  // each target is associated with an output LED pin and an input capacitive sensor pin. 
	targets[0] = Target( 3, 22);
  targets[1] = Target( 4, 24);
  targets[2] = Target( 5, 26);
  targets[3] = Target( 6, 28);
  targets[4] = Target( 7, 30);
  targets[5] = Target( 8, 32);
  targets[6] = Target( 9, 34);
  targets[7] = Target( 10, 36);
			
} 

// this should update the values within the targets array based upon the data coming from the Arduino input pins
void TextileSensor::updateTargetArray() {
  
  // two parts: 1. read pressures from the pins and update pressure & isTouched vals
  //            2. check play time on both tracks for each target and update isPlaying val
  
  //  iterate through all 8 targets
  for (int i = 0; i < 8; ++i ) {
    // read pins
    
    // check sounds
    targets[i].sounds[0].updateIsPlaying();
    targets[i].sounds[1].updateIsPlaying();
    
  }
    
  
}

// if both (or the one) target(s) that is blinking is being touched, return true
// otherwise return false
bool TextileSensor::allBlinkingTargetsTouched(LightCombo currBlinkCombo) {
  
  if(targets[currBlinkCombo.target1Index].touched && targets[currBlinkCombo.target2Index].touched) {
    return true; 
  } 
  return false;
  
}
