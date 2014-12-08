#ifndef TEXTILESENSOR_H
#define TEXTILESENSOR_H

#include "target.h"
#include "lightcombo.h"


//static double diff_resistance = 0.1 ;

//Global Pins for Output
static int ledPinB1 = 46;                                 //Blue LED
static int ledPinB2 = 13;                                 //Blue LED
static int ledPinB3 = 44;                                 //Blue LED

static  int ledPinR1 = 12;                              //Red LED
static  int ledPinR2 = 11;                               //Red LED
static  int ledPinR3 = 8;                               //Red LED

static  int ledPinY1 = 9;                              	//Yellow LED
static  int ledPinY2 = 10;                             	//Yellow LED

//Global Pins for Analog Input
static  int analogPinB1 = A0;								//Blue Touch
static  int analogPinB2 = A1;								//Blue Touch
static  int analogPinB3 = A2;								//Blue Touch

static  int analogPinR1 = A3;								//Red Touch
static  int analogPinR2 = A4;								//Red Touch
static  int analogPinR3 = A5;								//Red Touch

static  int analogPinY1 = A6;								//Yellow Touch
static  int analogPinY2 = A7;								//Yellow Touch

//Global Pins that supply voltage for Analog Input
static  int voltPinB1 = 22;
//static  int voltPinB2 = 23;
//static  int voltPinB3 = 24;
//
//static  int voltPinR1 = 25;
//static  int voltPinR2 = 26;
//static  int voltPinR3 = 27;
//
//static  int voltPinY1 = 28;
//static  int voltPinY2 = 29;


class TextileSensor { // this class should be friends with LEDController

public:
  //attr:
  Target targets[8];// = ; // hard code in and out pins for each of the 8 regions
  
  //methods:
  TextileSensor();

  bool calibrated(int& loopsLeft, const int totalLoops);

  void updateTargetArray();
  	// this should update the values within the targets array based upon the data coming from the Arduino input pins
  
  bool allBlinkingTargetsStretched(LightCombo currBlinkCombo);
  friend class LEDController;
};

#endif


