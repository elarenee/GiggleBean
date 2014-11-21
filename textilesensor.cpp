#include "textiltesensor.h"
 

TextileSensor::TextileSensor() {
	// Fill this in once we know the pin numbers for each target
  // each target is associated with an output LED pin and an input capacitive sensor pin. 
	targets[0] = Target( ledPinB1, analogPinB1, capSensPinB1_1, capSensPinB1_2);
 	targets[1] = Target( ledPinB2, analogPinB2, capSensPinB2_1, capSensPinB2_2);
  	targets[2] = Target( ledPinB3, analogPinB3, capSensPinB3_1, capSensPinB3_2);
 	targets[3] = Target( ledPinR1, analogPinR1, capSensPinR1_1, capSensPinR1_2);
  	targets[4] = Target( ledPinR2, analogPinR2, capSensPinR2_1, capSensPinR2_2);
  	targets[5] = Target( ledPinR3, analogPinR3, capSensPinR3_1, capSensPinR3_2);
  	targets[6] = Target( ledPinY1, analogPinY1, capSensPinY1_1, capSensPinY1_2);
  	targets[7] = Target( ledPinY2, analogPinY2, capSensPinY2_1, capSensPinY2_2);
			
} 

// this should update the values within the targets array based upon the data coming from the Arduino input pins
void TextileSensor::updateTargetArray() {
  
  // two parts: 1. read pressures from the pins and update pressure & isTouched vals
  //            2. check play time on both tracks for each target and update isPlaying val
  
  //  iterate through all 8 targets
  for (int i = 0; i < 8; ++i ) {
    // read pins
    if(digitalRead(targets[i].capSensPin) == 1) {
      targets[i].touched = true;
      double temp_resistance = analogRead(targets[i].analogPin);
      if(((temp_resistance - target[i].resistanceReading) / target[i].resistanceReading) > diff_resistance) {
        target[i].stretched = true;
      }
      else {
        target[i].stretched = false;
      }
    }
    else {
      targets[i].touched = false;
      target[i].resistanceReading = analogRead(targets[i].analogPin);
    }

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
