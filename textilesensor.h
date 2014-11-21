#ifndef TEXTILESENSOR_H
#define TEXTILESENSOR_H

#include "target.h"
#include "lightcombo.h"

//Global Pins for Output
static int ledPinB1 = 3;                                 //Blue LED
static int ledPinB2 = 4;                                 //Blue LED
static int ledPinB3 = 5;                                 //Blue LED

static  int ledPinR1 = 6;                              	//Red LED
static  int ledPinR2 = 7;                               	//Red LED
static  int ledPinR3 = 8;                                	//Red LED

static  int ledPinY1 = 9;                              	//Yellow LED
static  int ledPinY2 = 10;                             	//Yellow LED

//Global Pins for Input
static  int touchPinB1 = 22;								//Blue Touch
static   int touchPinB2 = 24;								//Blue Touch
static   int touchPinB3 = 26;								//Blue Touch

 static int touchPinR1 = 28;								//Red Touch
static  int touchPinR2 = 30;								//Red Touch
static  int touchPinR3 = 32;								//Red Touch

static  int touchPinY1 = 34;								//Yellow Touch
static  int touchPinY2 = 36;								//Yellow Touch



class TextileSensor { // this class should be friends with LEDController

public:

  //attr:
  Target targets[8];// = ; // hard code in and out pins for each of the 8 regions
  
  //methods:
  TextileSensor();
  void updateTargetArray();
  	// this should update the values within the targets array based upon the data coming from the Arduino input pins
  
  bool allBlinkingTargetsTouched(LightCombo currBlinkCombo);

};

#endif


