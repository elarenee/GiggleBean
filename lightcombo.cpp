#include "lightcombo.h"

//constructor
LightCombo::LightCombo(int a, int b, Color c) {
	target1Index = a;
	target2Index = b;
	color = c;
}

//copy constructor
LightCombo::LightCombo(const LightCombo& from) {
	target1Index = from.target1Index;
	target2Index = from.target2Index;
	color = from.color;
}

// default constructor
LightCombo::LightCombo() {
	target1Index = -1;
	target2Index = -1;
}

// returns the integer index value associated with the color of this blinkCombo
int LightCombo::getTrackIndex() {
  return (int)color;
}
