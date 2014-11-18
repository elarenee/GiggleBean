#ifndef DJ_H
#define DJ_H

#include "speaker.h"
#include "lightcombo.h"
#include "target.h"
#include "textilesensor.h"

#define PRESSURE_MIDLINE 300
// the PRESSURE_MIDLINE value should be figured out during testing. 

class DJ {

  //attr:
  Speaker speaker;
  
  //methods:
  void determineSong(LightCombo currBlinkCombo, const Target targets[]);
  
  void determineSound(const Target targets[]);
  
  void adjustVolume(LightCombo currBlinkCombo, const Target targets[]);

};

#endif





