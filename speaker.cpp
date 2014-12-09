#include "speaker.h"


Speaker::Speaker() {

//  defaultVolume = 100;
  songsPlaying[0] = false;//Track(14500); //10000//put these into milliseconds
  songsPlaying[1] = false;//Track(14500);//16500
  songsPlaying[2] = false;//Track(14500);//15000
  
 // sounds[0] = false;//Track(SOUND_DURATION);
 // sounds[1] = false;//Track(SOUND_DURATION);

}
  
// void Speaker::playTrack (TrackType trackType, int idx, int vol) {
//   // this function should send these three parameters over bluetooth 
//   // to the tablet
//  // Serial.println("sending playTrack data to Android");
  
// }

// int Speaker::convertPressureToVolume(double pressure) {
//   // somehow convert pressure to a "volume" integer and add it to additional volume
//   int volume = defaultVolume + pressure/*some equation with constants here*/; // we'll lose precision here, but it's ok!
//   return volume;
// }

bool Speaker::songPlaying() {
  
  if(songsPlaying[0] || songsPlaying[1] || songsPlaying[2]) {
    return true;
  }
 
   // if no songs are currently playing
   return false;
 
}

// void Speaker::updateSongs(bool& songEnded) {
//     //loop through songs
//     bool songJustEnded = false;
//     for (int i = 0; i < 3; ++i) {  //Serial.println("about to call update is playing for the song");

//         songJustEnded = songs[i].updateIsPlaying();
//         if (songJustEnded)
//           songEnded = true;
//     }
// }

// void Speaker::updateSounds() {
//     sounds[0].updateIsPlaying();
//     sounds[1].updateIsPlaying();
// }
