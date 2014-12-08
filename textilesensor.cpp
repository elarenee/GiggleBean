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

bool TextileSensor::calibrated(int& loopsLeft, const int totalLoops) {
  //loops starts at 3. if 0 we are calibrated
  if (loopsLeft < 1)
  {
    return true;
  }
    //  iterate through all 8 targets
  for (int i = 0; i < 8; i++ ) {
    int res = analogRead(targets[i].analogPin);
    if (res <= 10)
    { 
      // String st = "target ";
      // String st2 = st + i;
      // String st3 = " <= 0.";
      // st = st2 + st3;
      // Serial.println(st);
      //if any of the targets still aren't getting values, we want to start calibration over
      loopsLeft = totalLoops;
      for (int j = 0; j < 8; ++j)
      {
        targets[j].baselineRes = 0;
        
      }
      return false;
    }
    targets[i].baselineRes += res;
  }
  loopsLeft--;
  delay(300);
  //calibrate if we've read all
  if (loopsLeft < 1)
  {
  //  Serial.println("Calibrated");
    //  iterate through all 8 targets
    for (int i = 0; i < 8; i++ ) {
        targets[i].baselineRes /= totalLoops;
    //    Serial.println(targets[i].baselineRes);
    }
    return true;
  }
  return false;
}

void recalibrateTarget(Target& t) {

  // recalibrate this target's baseLineRes here
  t.baselineRes = 0;
  for (int j = 0; j < sizeMemArray; ++j) {
    t.baselineRes += t.resistanceReadings[j];
  }
  t.baselineRes /= sizeMemArray;

}

// this should update the values within the targets array based upon the data coming from the Arduino input pins
// returns false if the values have to be recalibrated; true otherwise
void TextileSensor::updateTargetArray() {
  
  //read resistance from the pins and update resistance & isTouched and isStretched vals
      //    String s = "memArrayIndex: ";
      //    String s2 = s + memArrayIndex;
      // Serial.println(s2);
  //  iterate through all 8 targets

//    Serial.println(analogRead(targets[7].analogPin));
//    Serial.println("baseline:");
//    Serial.println(targets[7].baselineRes);
//    delay(200);
    
    if (memArrayIndex < sizeMemArray) { // read in values
      for (int i = 0; i < 8; i++ ) {
        double res = analogRead(targets[i].analogPin);

        // if target is reading in weird values <= 10
        /*if(res <= 10) {
          // want to pause here and ask the user to shake the structure so that everything can be recalibrated.
          // maybe flash all the lights or play a quick mp3 that says "Shake me!"
          Serial.println("SHAKE ME!");
          delay(5000);
        } */
        targets[i].resistanceReadings[memArrayIndex] = analogRead(targets[i].analogPin);
      }
      memArrayIndex++;
    }
    else {   //do some logic on the past resistance readings
      memArrayIndex = 0;
      for (int i = 0; i < 8; i++ ) {

        
        // Serial.println(targets[i].baselineRes);
        // String str1 = "target [";
        // String str2 = str1 + i;
        // int x =targets[i].resistanceReadings[0]-targets[i].baselineRes;
        // String str3 = str2 + "]: " + x;
        // Serial.println(str3);


        targets[i].stretched = false;
        targets[i].touched = false;
        //if the resistance is over the high threshold, we have a stretch
        for (int j = 0; j < sizeMemArray; ++j)
        {
          if (targets[i].resistanceReadings[j] - targets[i].baselineRes > targets[i].highResInterval) {
            targets[i].stretched = true;
            targets[i].cyclesTouched = 0;
            targets[i].cyclesStretched++;
            targets[i].cyclesSinceRelease = 0;
            // s = "target ";
            // s2 = s + i;
            // s = s2 + " stretched";
            // Serial.println(s);
          }
        } 

        //if it wasn't just stretched, maybe we have a gentle touch
        if (!targets[i].stretched) {
          for (int j = 0; j < sizeMemArray; ++j)
          {
            if (targets[i].baselineRes - targets[i].resistanceReadings[j] > targets[i].lowResInterval) {
              targets[i].touched = true;
              targets[i].cyclesStretched = 0;
              targets[i].cyclesTouched++;
              targets[i].cyclesSinceRelease = 0;

            }
          } 
        }

        //if not touched or stretched, let's calibrate
        if (!targets[i].touched && !targets[i].stretched) {
          targets[i].cyclesTouched = targets[i].cyclesStretched = 0;
          if (targets[i].cyclesSinceRelease++ > 20) {
            recalibrateTarget(targets[i]);
          }
        }

        // if a target has been giggling or bo'inging for too long, recalibrate it
        if(targets[i].cyclesTouched >= 20 || targets[i].cyclesStretched >= 20) {

          recalibrateTarget(targets[i]);
          targets[i].cyclesTouched = targets[i].cyclesStretched = 0;
        }


        
        //FOR TESTING
    //Serial.println(targets[i].touched);
    //Serial.println(targets[i].stretched);
    //Serial.println(i);
    // Serial.println(targets[i].baselineRes);
    // String str1 = "target [";
    // String str2 = str1 + i;
    // String str3 = str2 + "]: " + targets[i].resistanceReadings[0]+ targets[i].resistanceReadings[1]+ targets[i].resistanceReadings[2];
    // Serial.println(str3);
      }

   }

  

 // delay(500);
 // Serial.println();

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
  
  if(targets[currBlinkCombo.target1Index].stretched && 
    (currBlinkCombo.target2Index == -1 || targets[currBlinkCombo.target2Index].stretched)) {
    return true; 
  } else {
    return false;
  }
}


