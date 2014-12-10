#include "textilesensor.h"


TextileSensor::TextileSensor() {
        // each target is associated with an output LED pin and an input analog pin. 
        // TODO: find low and high resistance defaults for each target
	targets[0] = Target( ledPinB1, analogPinB1, defaultLowResInterval, defaultHighResInterval);
 	targets[1] = Target( ledPinB2, analogPinB2, defaultLowResInterval, defaultHighResInterval);
 	targets[2] = Target( ledPinB3, analogPinB3, defaultLowResInterval, defaultHighResInterval);
 	targets[3] = Target( ledPinR1, analogPinR1, defaultLowResInterval, defaultHighResInterval);
  	targets[4] = Target( ledPinR2, analogPinR2, defaultLowResInterval, defaultHighResInterval); 
  	targets[5] = Target( ledPinR3, analogPinR3, defaultLowResInterval, 15); 
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
      Serial.println(i); //This line to figure out problem pin
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
        targets[i].resistanceReadings[memArrayIndex] = analogRead(targets[i].analogPin);
        //Serial.println("baseline:");
       ;
        
      }
      memArrayIndex++;
    }
    else {   //do some logic on the past resistance readings
      memArrayIndex = 0;
      for (int i = 0; i < 8; i++ ) {

//        Serial.println("baseline:");
//        Serial.println(targets[i].baselineRes);
//        for (int j = 0; j < sizeMemArray; ++j)
//        {
//          Serial.println(targets[i].resistanceReadings[j]);
//        }
        // String str1 = "target [";
        // String str2 = str1 + i;
        // int x =targets[i].resistanceReadings[0];
        // String str3 = str2 + "]: " + x;
        // Serial.println(str3);

        bool wasStretched = targets[i].stretched;
        bool wasTouched = targets[i].touched;
        targets[i].stretched = false;
        targets[i].touched = false;
        int avRes = 0;
        //The resistance may drop briefly after the release of a stretch, but it never jumps up oddly
        //So we check for 1 high value for a stretch, and an AVERAGE low value for a touch

        //also, since it drops and the touch is so sensitive, we need to recalibrate as soon as it stops being stretched
        for (int j = 0; j < sizeMemArray; ++j)
        {
          int res = targets[i].resistanceReadings[j];
          avRes += res;
          //if the resistance is over the high threshold, we have a STRETCH
          if ( res - targets[i].baselineRes > targets[i].highResInterval) {
            targets[i].stretched = true;
            targets[i].cyclesTouched = 0;
            targets[i].cyclesStretched++;
            targets[i].cyclesSinceRelease = 0;
            break;
            // s = "target ";
            // s2 = s + i;
            // s = s2 + " stretched";
            // Serial.println(s);
          }
          //once we've looked at all values and none are stretch, check if average is low (TOUCH)
          if (j==sizeMemArray-1) { 
            avRes /= sizeMemArray;
            //if it was previously stretched, it will have just dropped and we should recalibrate
            //but since the value will be rising, it will be impossible to get it to giggle if we set
            //it at the avRes, so we add a buffer
            if (wasStretched) {
              targets[i].baselineRes = avRes+10;
            }
            else {
              //wasn't just stretched.
              //we get stuck giggling sometimes, so don't giggle twice in a row, recalibrate
              if (wasTouched) {
                targets[i].baselineRes = avRes;
              }
              //we check if resistance is low (if so we have a touch)
              else if (targets[i].baselineRes - avRes > targets[i].lowResInterval) {
                targets[i].touched = true;
                targets[i].cyclesStretched = 0;
                targets[i].cyclesTouched++;
                targets[i].cyclesSinceRelease = 0;
              }
              //otherwise we might as well calibrate
              //but here we might still be rising from post stretch recovery
              else {
                if (avRes > targets[i].baselineRes + 5)
                {
                  targets[i].baselineRes = avRes + 10; //try to stay ahead of the rebound
                }
                targets[i].baselineRes = avRes; //otherwise, this is probably just a normal flux
              }
            }
          }
        } 

        // //TOUCH if it wasn't just stretched, maybe we have a gentle touch
        // if (!targets[i].stretched) {
        //   for (int j = 0; j < sizeMemArray; ++j)
        //   {
        //     if (targets[i].baselineRes - targets[i].resistanceReadings[j] > targets[i].lowResInterval) {
        //       targets[i].touched = true;
        //       targets[i].cyclesStretched = 0;
        //       targets[i].cyclesTouched++;
        //       targets[i].cyclesSinceRelease = 0;
        //       break;
        //     }
        //   } 
        // }

        //if not touched or stretched, let's calibrate
        // if (!targets[i].touched && !targets[i].stretched) {
        //   targets[i].cyclesTouched = targets[i].cyclesStretched = 0;
        //   if (targets[i].cyclesSinceRelease++ > 20) {
        //     recalibrateTarget(targets[i]);
        //   }
        // }

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
    //Serial.println(analogRead(targets[7].analogPin));
   }
}

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


