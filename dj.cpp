#include "dj.h"
#include "lightcombo.h"
#include "target.h"
#include "textilesensor.h"

void DJ::determineSong(LightCombo currBlinkCombo, const Target[] targets) {
  
    int target1_idx = currBlinkCombo.target1Index;
    
    double pressure = targets[target1_idx].pressureReading;
    
    int new_vol = this.speaker.convertPressureToVolume(pressure);
    
    int itrack_dx = currBlinkCombo.getTrackIndex();
    
    this.speaker.playTrack(new_vol, track_idx, TrackType.Song);
    
}

void DJ::adjustVolume(LightCombo currBlinkCombo) {
  
    int target1_idx = currBlinkCombo.target1Index;
    
    double pressure = targets[target1_idx].pressureReading;
     
    int new_vol = this.speaker.convertPressureToVolume(pressure);
    
    //this will send the new volume, but in order to specify that it is just increasing
    // the volume for a second and not restarting a track, the second parameter should be -1
    this.speaker.playTrack(new_vol, -1, TrackType.Song);
    
}

void DJ::determineSound(const Target[] targets) {
  
    for(int i = 0; i < 8; i++) {
      
       if(targets[i].touched && !targets[i].isPlaying) {
         
          int idx;
          
          // "hard" touch -> bo'ing
          if(targets[i].pressureReading >  PRESSURE_MIDLINE) 
            idx = 1;
          // "soft" touch -> giggle
          else             
           idx = 2; 
          
          int vol = speaker.defaultVolume; // there should be no volume regulation 
          this.speaker.PlayTrack(vol, idx, TrackType.Sound);
          targets[i].startTrack();
          
       }
    }
  
    
        
}
