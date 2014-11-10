class LEDController {

  //attr:
  LightCombo currentBlinkCombo; // this is the current combination of targets that are currently blinking on the bean. it is set and reset by this class’s shuffleBlink() method
  
  LightCombo lightCombos[15] = {LightCombo(0,1,Color.BLUE), LightCombo(1,5,Color.BLUE), LightCombo(0,5,Color.BLUE), 
  LightCombo(0,-1,Color.BLUE), LightCombo(1,-1,Color.BLUE), LightCombo(5,-1,Color.BLUE), LightCombo(2,3,Color.RED), 
  LightCombo(3,7,Color.RED), LightCombo(2,7,Color.RED), LightCombo(2,-1,Color.RED), ........... }; // this is the hard-coded array of possible combinations of targets that can be blinking simultaneously. We have to hard-code these values because we only want LEDs that are of the same color to be blinking at the same time. 
  
  //methods:
  void stopBlinking() {
  	// make all LEDs steady (no blinking/pulsing anywhere)
  }
  
  void shuffleBlinkingLEDs() {
    this.currentBlinkCombo	
  }
  void makeBlink(int index) {
	// make the specified target region blink (needs to access the targets[] array within TextileSensor)
	// directly modify the pin associated with that target
  }
  
  LightCombo getCurBlinkCombo() {
  	return this.currentBlinkCombo;
  }

};

