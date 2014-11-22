#include "textilesensor.h"


TextileSensor::TextileSensor() {
	// Fill this in once we know the pin numbers for each target
        // each target is associated with an output LED pin and an input capacitive sensor pin. 
	targets[0] = Target( ledPinB1, analogPinB1, capSensPinB1);
 	targets[1] = Target( ledPinB2, analogPinB2, capSensPinB2);
  	targets[2] = Target( ledPinB3, analogPinB3, capSensPinB3);
 	targets[3] = Target( ledPinR1, analogPinR1, capSensPinR1);
  	targets[4] = Target( ledPinR2, analogPinR2, capSensPinR2);
  	targets[5] = Target( ledPinR3, analogPinR3, capSensPinR3);
  	targets[6] = Target( ledPinY1, analogPinY1, capSensPinY1);
  	targets[7] = Target( ledPinY2, analogPinY2, capSensPinY2);   		
} 


// this should update the values within the targets array based upon the data coming from the Arduino input pins
void TextileSensor::updateTargetArray() {
  
  // two parts: 1. read pressures from the pins and update pressure & isTouched vals
  //            2. check play time on both tracks for each target and update isPlaying val
  
  //  iterate through all 8 targets
  String label = "target: ";

  for (int i = 0; i < 1; i++ ) {
    int temp = analogRead(targets[i].analogPin);
//  read pins
    if (temp > 700) {
      targets[i].touched = true;
    } else {
      targets[i].touched = false;
    }
      //float temp_resistance = analogRead(targets[i].analogPin);
    if(temp > 750) {
      targets[i].stretched = true;
    } else {        
      targets[i].stretched = false;
    }
    delay(100);
    Serial.println(targets[i].touched);
    Serial.println(targets[i].stretched);
    Serial.println(temp);
  }
}
//      //digitalWrite(A15, 255);
//      double temp_resistance = analogRead(targets[i].analogPin);
//      if(((temp_resistance - targets[i].resistanceReading) / targets[i].resistanceReading) > diff_resistance) {
//        targets[i].stretched = true;
//      }
//      else {
//        targets[i].stretched = false;
//      }
//    }
//    else {
//      targets[i].touched = false;
//      //digitalWrite(A15, 255);
//      targets[i].resistanceReading = analogRead(targets[i].analogPin);
//    }

    // check sounds
    //targets[i].sounds[0].updateIsPlaying();
    //targets[i].sounds[1].updateIsPlaying()



////    // check sounds
////    targets[i].sounds[0].updateIsPlaying();
////    targets[i].sounds[1].updateIsPlaying();
////      Serial.println(targets[i].touched);
////      Serial.println(targets[i].stretched);
//      Serial.println(temp);
//      Serial.println(targets[i].touched);
//      Serial.println(targets[i].stretched);

  //  }
  
  


// if both (or the one) target(s) that is blinking is being touched, return true
// otherwise return false
bool TextileSensor::allBlinkingTargetsTouched(LightCombo currBlinkCombo) {
  
  if(targets[currBlinkCombo.target1Index].touched || targets[currBlinkCombo.target2Index].touched) {
    return true; 
  } else {
  return false;
  }
}


