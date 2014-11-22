#include "dj.h"

void DJ::determineSong(LightCombo currBlinkCombo, const Target targets[]) {
  
    int target1_idx = currBlinkCombo.target1Index;
    
    double pressure = targets[target1_idx].resistanceReading;
    
    int new_vol = speaker.convertPressureToVolume(pressure);
    
    int track_idx = currBlinkCombo.getTrackIndex();
    
    speaker.playTrack(new_vol, track_idx, Song);
    
}

void DJ::adjustVolume(LightCombo currBlinkCombo, const Target targets[]) {
  
    int target1_idx = currBlinkCombo.target1Index;
    
    double pressure = targets[target1_idx].resistanceReading;
     
    int new_vol = speaker.convertPressureToVolume(pressure);
    
    //this will send the new volume, but in order to specify that it is just increasing
    // the volume for a second and not restarting a track, the second parameter should be -1
    speaker.playTrack(new_vol, -1, Song);
    
}

void DJ::determineSound(Target targets[]) {
  
    for(int i = 0; i < 8; i++) {
      
       if(targets[i].touched && !targets[i].sounds[0].isPlaying && !targets[i].sounds[1].isPlaying) {
         
          int idx;
          
          // "hard" touch -> bo'ing
          if(targets[i].resistanceReading >  PRESSURE_MIDLINE) 
            idx = 1;
          // "soft" touch -> giggle
          else             
           idx = 2; 
          
          int vol = speaker.defaultVolume; // there should be no volume regulation 
          speaker.playTrack(vol, idx, Sound);
          targets[i].sounds[idx].startTrack();
          
       }
    }       
}
