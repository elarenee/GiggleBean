#include "dj.h"
#include "target.h"



void DJ::determineSong(LightCombo currBlinkCombo, const Target targets[]) {
  
    int target1_idx = currBlinkCombo.target1Index;
    
    double pressure = targets[target1_idx].resistanceReadings[sizeMemArray-1];
    
    int new_vol = speaker.convertPressureToVolume(pressure);
    
    int track_idx = currBlinkCombo.getTrackIndex();
    
    speaker.playTrack(Song, track_idx, new_vol);

    speaker.songs[track_idx].startTrack();
    
}

void DJ::adjustVolume(LightCombo currBlinkCombo, const Target targets[]) {
  
    int target1_idx = currBlinkCombo.target1Index;
    
    double pressure = targets[target1_idx].resistanceReadings[sizeMemArray-1];
     
    int new_vol = speaker.convertPressureToVolume(pressure);
    
    //this will send the new volume, but in order to specify that it is just increasing
    // the volume for a second and not restarting a track, the second parameter should be -1
    speaker.playTrack(Song, -1, new_vol);
    
}

void DJ::determineSound(Target targets[]) {
    //we can play at most 1 giggle and 1 bo'ing at a time
    for(int i = 0; i < 8; i++) {
        //play giggle if soft touch
        if (!speaker.sounds[0].isPlaying && targets[i].touched && !targets[i].stretched) {
          speaker.playTrack(Sound, 1, speaker.defaultVolume);
          speaker.sounds[0].startTrack();
        }

        //play bo'ing if stretch
        if(!speaker.sounds[1].isPlaying && targets[i].stretched) {
          speaker.playTrack(Sound, 2, speaker.defaultVolume);
          speaker.sounds[1].startTrack();
        }
    }       
}
