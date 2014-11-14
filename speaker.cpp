#include "speaker.h"


void Speaker::playTrack (int vol, int idx, TrackType trackType) {
  // this function should send these three parameters over bluetooth 
  // to the tablet
  
}

void Speaker::convertPressureToVolume(int pressure) {
  // somehow convert pressure to an "additional volume" integer
}

void Speaker::stopPlayingTrack() {
  
}

bool Speaker::songPlaying() {
  
 for(Sound const& s : this.songs) {
  if(s.isPlaying)
    return true;
 } 
 
 // if no songs are currently playing
 return false;
 
}
