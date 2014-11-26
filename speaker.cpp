#include "speaker.h"


Speaker::Speaker() {

  defaultVolume = 100;
  songs[0] = Track(10100); //10000//put these into milliseconds
  songs[1] = Track(19500);//16500
  songs[2] = Track(17500);//15000
  
  sounds[0] = Track(SOUND_DURATION);
  sounds[1] = Track(SOUND_DURATION);

}
  
void Speaker::playTrack (TrackType trackType, int idx, int vol) {
  // this function should send these three parameters over bluetooth 
  // to the tablet
 // Serial.println("sending playTrack data to Android");
  
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
    for (int i = 0; i < 3; ++i) {  //Serial.println("about to call update is playing for the song");

        songJustEnded = songs[i].updateIsPlaying();
        if (songJustEnded)
          songEnded = true;
    }
}

void Speaker::updateSounds() {
    sounds[0].updateIsPlaying();
    sounds[1].updateIsPlaying();
}
