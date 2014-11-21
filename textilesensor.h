
#ifndef TEXTILESENSOR_H
#define TEXTILESENSOR_H

#include "target.h"
#include "lightcombo.h"
#include <CapacitiveSensor.h>


static double diff_resistance = 0.1 ;

//Global Pins for Output
static int ledPinB1 = 3;                                 //Blue LED
static int ledPinB2 = 4;                                 //Blue LED
static int ledPinB3 = 5;                                 //Blue LED

static  int ledPinR1 = 6;                              	//Red LED
static  int ledPinR2 = 7;                               //Red LED
static  int ledPinR3 = 8;                               //Red LED

static  int ledPinY1 = 9;                              	//Yellow LED
static  int ledPinY2 = 10;                             	//Yellow LED

//Global Pins for Analog Input
static  int analogPinB1 = 0;								//Blue Touch
static  int analogPinB2 = 1;								//Blue Touch
static  int analogPinB3 = 2;								//Blue Touch

 static int analogPinR1 = 3;								//Red Touch
static  int analogPinR2 = 4;								//Red Touch
static  int analogPinR3 = 5;								//Red Touch

static  int analogPinY1 = 6;								//Yellow Touch
static  int analogPinY2 = 7;								//Yellow Touch

//Global Pins for Cap Sens Input
static    CapacitiveSensor capSensPinB1 = CapacitiveSensor(22,23);
static    CapacitiveSensor capSensPinB2 = CapacitiveSensor(24,25);
static    CapacitiveSensor capSensPinB3 = CapacitiveSensor(26,27);
static    CapacitiveSensor capSensPinR1 = CapacitiveSensor(28,29);
static    CapacitiveSensor capSensPinR2 = CapacitiveSensor(30,31);
static    CapacitiveSensor capSensPinR3 = CapacitiveSensor(32,33);
static    CapacitiveSensor capSensPinY1 = CapacitiveSensor(34,35);
static    CapacitiveSensor capSensPinY2 = CapacitiveSensor(36,37);

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


