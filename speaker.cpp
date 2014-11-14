#include "speaker.h"

void Track::startTrack() {
  time(startTime);
  isPlaying = true;
}

void Track::updateIsPlaying() {
  if (isPlaying) {
    time_t now;
    time(&now);
    if (duration <= difftime(now, startTime)) {
      isPlaying = false;
    }
  }
}
  
void Speaker::playTrack (int vol, int idx, TrackType trackType) {
  // this function should send these three parameters over bluetooth 
  // to the tablet
  
}

int Speaker::convertPressureToVolume(double pressure) {
  // somehow convert pressure to a "volume" integer and add it to additional volume
  int volume = this.defaultVolume + pressure/*some equation with constants here*/; // we'll lose precision here, but it's ok!
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

void Speaker::updateSongs() {
    //loop through songs
    for (int i = 0; i < 3; ++i) {
        this.songs[i].updateIsPlaying();
    }
}
