#include "speaker.h"


void Speaker::playTrack (int vol, int idx, TrackType trackType) {
  // this function should send these three parameters over bluetooth 
  // to the tablet
  
}

int Speaker::convertPressureToVolume(double pressure) {
  // somehow convert pressure to a "volume" integer and add it to additional volume
  int volume = this.defaultVolume + pressure/*500*/; // we'll lose precision here, but it's ok!
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

void updateSongs() {
  
}

void updateSounds() {
  
}
