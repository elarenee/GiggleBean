#include "dj.h"
#include "lightcombo.h"
#include "target.h"
#include "textilesensor.h"

void DJ::determineSong(Target target, LightCombo currBlinkCombo) {
  
    for(int i = 0; i < 8; i++) {
      
    }
    
    this.speaker.setVolume();
    
    this.speaker.PlayTrack(vol, idx, TrackType.Song);
    //calls PlayTrack (sends volume and array idx to tablet)
    
}

void DJ::determineSound(Target target) {
    
    this.speaker.setVolume();
  	
    this.speaker.PlayTrack(vol, idx, TrackType.Sound);
    //calls PlayTrack (sends volume and array idx to tablet)
        
}
