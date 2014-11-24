#include "textilesensor.h"


TextileSensor::TextileSensor() {
        // each target is associated with an output LED pin and an input analog pin. 
        // TO DO: find low and high resistance defaults for each target
	targets[0] = Target( ledPinB1, analogPinB1, defaultLowResInterval, defaultHighResInterval);
 	targets[1] = Target( ledPinB2, analogPinB2, defaultLowResInterval, defaultHighResInterval);
 	targets[2] = Target( ledPinB3, analogPinB3, defaultLowResInterval, defaultHighResInterval);
 	targets[3] = Target( ledPinR1, analogPinR1, defaultLowResInterval, defaultHighResInterval);
  	targets[4] = Target( ledPinR2, analogPinR2, defaultLowResInterval, defaultHighResInterval); 
  	targets[5] = Target( ledPinR3, analogPinR3, defaultLowResInterval, defaultHighResInterval); 
  	targets[6] = Target( ledPinY1, analogPinY1, defaultLowResInterval, defaultHighResInterval);
  	targets[7] = Target( ledPinY2, analogPinY2, defaultLowResInterval, defaultHighResInterval);   		
} 

bool TextileSensor::calibrated(int& loops) {
  //loops starts at 3. if 0 we are calibrated
  if (loops < 1)
  {
    return true;
  }
    //  iterate through all 8 targets
  for (int i = 0; i < 8; i++ ) {
    targets[i].resistanceReadings[loops-1] = analogRead(targets[i].analogPin);
  }
  loops--;
  //calibrate if we've read 3
  if (loops < 1)
  {
    //  iterate through all 8 targets
    for (int i = 0; i < 8; i++ ) {
        targets[i].baselineRes = 0;
        for (int j = 0; j < sizeMemArray; ++j)
        {
          targets[i].baselineRes += targets[i].resistanceReadings[j];
        }
        targets[i].baselineRes /= sizeMemArray;
    }
    return true;
  }
  return false;

}
// this should update the values within the targets array based upon the data coming from the Arduino input pins
void TextileSensor::updateTargetArray() {
  
  //read resistance from the pins and update resistance & isTouched and isStretched vals
   
  //  iterate through all 8 targets
  for (int i = 6; i < 7; i++ ) {
    if (memArrayIndex < sizeMemArray) {
      targets[i].resistanceReadings[memArrayIndex++] = analogRead(targets[i].analogPin);
    }
    else { //do some logic on the past resistance readings
      memArrayIndex = 0;
      //if the resistance is over the high threshold, we have a stretch
      for (int j = 0; j < sizeMemArray; ++j)
      {
        if (targets[i].resistanceReadings[j] - targets[i].baselineRes > targets[i].highResInterval) {
          targets[i].stretched = true;
        }
      } 
      //if it wasn't just stretched, maybe we have a gentle touch
      if (!targets[i].stretched) {
        for (int j = 0; j < sizeMemArray; ++j)
        {
          if (targets[i].baselineRes - targets[i].resistanceReadings[j] > targets[i].lowResInterval) {
            targets[i].touched = true;
          }
        } 
      }
      //if not touched or stretched, let's calibrate
      if (!targets[i].touched && !targets[i].stretched) {
        targets[i].baselineRes = 0;
        for (int j = 0; j < sizeMemArray; ++j)
        {
          targets[i].baselineRes += targets[i].resistanceReadings[j];
        }
        targets[i].baselineRes /= sizeMemArray;
      }
   }
//FOR TESTING
    //Serial.println(targets[i].touched);
    //Serial.println(targets[i].stretched);
    //Serial.println(i);
    String str1 = "target [";
    String str2 = str1 + i;
    String str3 = str2 + "]: " + targets[i].resistanceReadings[0]+ targets[i].resistanceReadings[1]+ targets[i].resistanceReadings[2];
    Serial.println(str3);
  }
 // delay(100);
  Serial.println();
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
bool TextileSensor::allBlinkingTargetsStretched(LightCombo currBlinkCombo) {
  
  if(targets[currBlinkCombo.target1Index].touched && 
    (currBlinkCombo.target2Index == -1 || targets[currBlinkCombo.target2Index].touched)) {
    return true; 
  } else {
    return false;
  }
}


