#include "speaker.h"


void Speaker::playTrack (int vol, int idx, TrackType trackType) {
  // this function should send these three parameters over bluetooth 
  // to the tablet
  
}

void Speaker::setVolume() {
  
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
