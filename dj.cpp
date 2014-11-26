#include "dj.h"

void DJ::determineSong(LightCombo currBlinkCombo, const Target targets[]) {
  
    int target1_idx = currBlinkCombo.target1Index;
    
    double pressure = targets[target1_idx].resistanceReading;
    
    int new_vol = speaker.convertPressureToVolume(pressure);
    
    int track_idx = currBlinkCombo.getTrackIndex();
    
    speaker.playTrack(Song, track_idx, new_vol);
}

void DJ::adjustVolume(LightCombo currBlinkCombo, const Target targets[]) {
  
    int target1_idx = currBlinkCombo.target1Index;
    
    double pressure = targets[target1_idx].resistanceReading;
     
    int new_vol = speaker.convertPressureToVolume(pressure);
    
    //this will send the new volume, but in order to specify that it is just increasing
    // the volume for a second and not restarting a track, the second parameter should be -1
    speaker.playTrack(Song, -1, new_vol);
    
}

void DJ::determineSound(Target targets[]) {
    //we can play at most 1 giggle and 1 bo'ing at a time
    for(int i = 0; i < 8; i++) {
      unsigned long timer1;
      unsigned long timer2;
        //play giggle if soft touch
        if (targets[i].touched && targets[i].stretched) {
          Serial.println("222");
          speaker.playTrack(Sound, 1, speaker.defaultVolume);
          speaker.sounds[0].startTrack();
        }

        //play bo'ing if stretch
        if(!speaker.sounds[1].isPlaying && targets[i].stretched) {
          Serial.println("111");
          speaker.playTrack(Sound, 2, speaker.defaultVolume);
          speaker.sounds[1].startTrack();
        }
    }     
}
