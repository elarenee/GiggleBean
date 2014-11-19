#ifndef TEXTILESENSOR_H
#define TEXTILESENSOR_H

#include "target.h"
#include "lightcombo.h"

//Global Pins for Output
  int ledPinB1 = 3;                                 //Blue LED
  int ledPinB2 = 4;                                 //Blue LED
  int ledPinB3 = 5;                                 //Blue LED

  int ledPinR1 = 6;                              	//Red LED
  int ledPinR2 = 7;                               	//Red LED
  int ledPinR3 = 8;                                	//Red LED

  int ledPinY1 = 9;                              	//Yellow LED
  int ledPinY2 = 10;                             	//Yellow LED

//Global Pins for Input
  int touchPinB1 = 22;								//Blue Touch
  int touchPinB2 = 24;								//Blue Touch
  int touchPinB3 = 26;								//Blue Touch

  int touchPinR1 = 28;								//Red Touch
  int touchPinR2 = 30;								//Red Touch
  int touchPinR3 = 32;								//Red Touch

  int touchPinY1 = 34;								//Yellow Touch
  int touchPinY2 = 36;								//Yellow Touch



class TextileSensor { // this class should be friends with LEDController

public:

  //attr:
  Target targets[8];// = ; // hard code in and out pins for each of the 8 regions
  
  //methods:
  void updateTargetArray();
  	// this should update the values within the targets array based upon the data coming from the Arduino input pins
  
  bool allBlinkingTargetsTouched(LightCombo currBlinkCombo);

};

#endif


