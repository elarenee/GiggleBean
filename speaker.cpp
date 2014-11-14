#include "speaker.h"


void Speaker::playTrack (int vol, int idx, TrackType trackType) {
  // this function should send these three parameters over bluetooth 
  // to the tablet
  
}

int Speaker::convertPressureToVolume(int pressure) {
  // somehow convert pressure to a "volume" integer and add it to additional volume
  int volume = this.defaultVolume + pressure/*500*/;
  return volume;
}

bool Speaker::songPlaying() {
  
   for(Sound const& s : this.songs) {
    if(s.isPlaying)
      return true;
   } 
 
   // if no songs are currently playing
   return false;
 
}

void Speaker::updateSongs(Target[] targetArray) {
    //loop through songs
    for (int i = 0; i < 3; ++i) {
        //check the targetArray and update each song accordingly
        
    }
}

void Speaker::updateSounds(Target[] targetArray) {
    //loop through sounds
    for (int i = 0; i < 2; ++i) {
        //check the targetArray and update each song accordingly
        
    }
}
