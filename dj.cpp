#include "dj.h"
#include "lightcombo.h"
#include "target.h"
#include "textilesensor.h"

void DJ::determineSong(Target target, LightCombo currBlinkCombo) {
  
    for(int i = 0; i < 8; i++) {
      
    }
    
    int new_vol = this.speaker.convertPressureToVolume();
    
    this.speaker.PlayTrack(new_vol, idx, TrackType.Song);
    //calls PlayTrack (sends volume and array idx to tablet)
    
}

void DJ::determineSound(Target target) {
    
  	
    this.speaker.PlayTrack(vol, idx, TrackType.Sound);
    //calls PlayTrack (sends volume and array idx to tablet)
        
}
