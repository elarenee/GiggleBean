#include "dj.h"
#include "lightcombo.h"
#include "target.h"
#include "textilesensor.h"

void DJ::determineSong(LightCombo currBlinkCombo, const Target[] targets) {
  
    int target1_idx = currBlinkCombo.target1Index;
    
    double pressure = targets[target1_idx].pressureReading;
    
    int new_vol = this.speaker.convertPressureToVolume(pressure);
    
    int itrack_dx = currBlinkCombo.getTrackIndex();
    
    this.speaker.PlayTrack(new_vol, track_idx, TrackType.Song);
    
}

void DJ::determineSound(const Target[] targets) {
  
    double pressure = targets.pressureReading; 
    
    int vol = speaker.defaultVolume; // there should be no volume regulation 
  	
    this.speaker.PlayTrack(vol, idx, TrackType.Sound);
    //calls PlayTrack (sends volume and array idx to tablet)
        
}
