#include "lightcombo.h"

//constructor
LightCombo::LightCombo(int a, int b, Color c) {
	target1Index = a;
	target2Index = b;
	color = c;
}

//copy constructor
LightCombo::LightCombo(LightCombo from) {
	target1Index = from.target1Index;
	target2Index = from.target2Index;
	color = from.color;
}

