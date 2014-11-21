#ifndef TEXTILESENSOR_H
#define TEXTILESENSOR_H

#include "target.h"
#include "lightcombo.h"

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
static  int capSensPinB1_1 = 22;								//Blue Touch
static  int capSensPinB1_2 = 23;								//Blue Touch
static  int capSensPinB2_1 = 24;								//Blue Touch
static  int capSensPinB2_2 = 25;								//Blue Touch
static  int capSensPinB3_1 = 26;								//Blue Touch
static  int capSensPinB3_2 = 27;								//Blue Touch

static 	int capSensPinR1_1 = 28;								//Red Touch
static  int capSensPinR1_2 = 29;								//Red Touch
static 	int capSensPinR2_1 = 30;								//Red Touch
static  int capSensPinR2_2 = 31;								//Red Touch
static 	int capSensPinR3_1 = 32;								//Red Touch
static  int capSensPinR3_2 = 33;								//Red Touch

static  int capSensPinY1_1 = 34;								//Yellow Touch
static  int capSensPinY1_2 = 35;								//Yellow Touch
static  int capSensPinY2_1 = 36;								//Yellow Touch
static  int capSensPinY2_2 = 37;								//Yellow Touch

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


