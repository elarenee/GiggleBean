#ifndef LIGHTCOMBO_H
#define LIGHTCOMBO_H

#include <cstdlib>

enum Color { RED, BLUE, YELLOW };

class LightCombo {
    
public:
  
  //attr:

  // NOTE: These two integers will range from 0-7 because there are 8 possible target regions
  // for pairs, both targets have values. target1 is the target Ara can reach.
  // for single targets, target1 has a value and target2 is -1.
  int target1Index; // use this target to get pressure reading for volume control. this should be Ara's target, if possible.
  int target2Index; // -1 if not a target pair
  
  
  // I’ve moved “color” from Target to LightCombo because it is never used within the TextileSensor class. 
  // One layer of indirection has been removed.
  Color color; 

  //constructor
  LightCombo(int a, int b, Color c);
  
  //copy constructor
  LightCombo(const LightCombo& from);

  // default constructor
  LightCombo();
  
  int getTrackIndex();

};

#endif

