enum Color { RED, BLUE, YELLOW};

class LightCombo {

  //attr:
  
  int target1index; // this target region should be reachable by Dad
  int target2index; // and for consistency, this second value should always be the region that can be reached by Ara (height constraint)
  
  // NOTE: ^^ These two integers ^^ will range from 0-7 because there are only 8 possible target regions
  // however, if one of them is set as -1, this means that the combination only consists of one target region. i.e. only one region on the target is being lit up (presumably because it is only within Dad’s reach and Ara will be forced to ask Dad to help her)
  
  Color color; // I’ve moved “color” from Target to LightCombo because it is never used within the TextileSensor class anyway. One layer of indirection has been removed. Anyway, it’s an attribute associated with LEDs, therefore, it should be in an LED-associated class
  
  //constructor
  LightCombo::LightCombo(int a, int b, Color c) {
  	target1Index = a;
  	target2Index = b;
  	color = c;
  }

};

