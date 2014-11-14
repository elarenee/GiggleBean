#include <cmath>

#include "dj.h"
#include "lightcombo.h"
#include "target.h"
#include "textilesensor.h"

void DJ::determineSong(Target target, LightCombo currBlinkCombo) {
  
    
    int pressure = max(target[currBlinkCombo.target1Index].pressureReading, target[currBlinkCombo.target2Index].pressureReading);
    this.speaker.setVolume(pressure);
    
    int vol = speaker.defaultVolume + speaker.additionalVolume;
    
    this.speaker.PlayTrack(vol, idx, TrackType.Song);
    //calls PlayTrack (sends volume and array idx to tablet)
    
}

void DJ::determineSound(Target target) {
    
    this.speaker.setVolume();
  	
    this.speaker.PlayTrack(vol, idx, TrackType.Sound);
    //calls PlayTrack (sends volume and array idx to tablet)
        
}
