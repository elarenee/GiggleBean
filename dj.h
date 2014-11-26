#ifndef DJ_H
#define DJ_H

#include "speaker.h"
#include "lightcombo.h"
#include "target.h"

#define PRESSURE_MIDLINE 300
// the PRESSURE_MIDLINE value should be figured out during testing. 

class DJ {

public:
  //attr:
  Speaker speaker;
  bool isSoundPlaying;
  //methods:
  void determineSong(LightCombo currBlinkCombo, const Target targets[]);
  
  void determineSound(Target targets[]);
  
  void adjustVolume(LightCombo currBlinkCombo, const Target targets[]);

};

#endif





