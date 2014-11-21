#include "speaker.h"

  
void Speaker::playTrack (int vol, int idx, TrackType trackType) {
  // this function should send these three parameters over bluetooth 
  // to the tablet
  
}

int Speaker::convertPressureToVolume(double pressure) {
  // somehow convert pressure to a "volume" integer and add it to additional volume
  int volume = defaultVolume + pressure/*some equation with constants here*/; // we'll lose precision here, but it's ok!
  return volume;
}

bool Speaker::songPlaying() {
  
  if(songs[0].isPlaying || songs[1].isPlaying || songs[2].isPlaying) {
    return true;
  }
 
   // if no songs are currently playing
   return false;
 
}

void Speaker::updateSongs(bool& songEnded) {
    //loop through songs
    bool songJustEnded = false;
    for (int i = 0; i < 3; ++i) {
        songJustEnded = songs[i].updateIsPlaying();
        if (songJustEnded)
          songEnded = true;
    }
}
