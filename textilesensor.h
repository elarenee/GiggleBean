#ifndef TEXTILESENSOR_H
#define TEXTILESENSOR_H

#include "target.h"
#include "lightcombo.h"


  int ledPinB1 = 3;                                 //Blue LED
  int ledPinB2 = 4;                                 //Blue LED
  int ledPinB3 = 5;                                 //Blue LED

  int ledPinR1 = 6;                                //Red LED
  int ledPinR2 = 7;                                //Red LED
  int ledPinR3 = 8;                                //Red LED

  int ledPinY1 = 9;                                //Yellow LED
  int ledPinY2 = 10;                                //Yellow LED


class TextileSensor { // this class should be friends with LEDController

friend class DJ;

  //attr:
  Target targets[8];// = ; // hard code in and out pins for each of the 8 regions
  
protected:
  //methods:
  void updateTargetArray();
  	// this should update the values within the targets array based upon the data coming from the Arduino input pins
  
  bool allBlinkingTargetsTouched(LightCombo currBlinkCombo);

};

#endif


