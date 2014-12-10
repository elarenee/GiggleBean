#ifndef SPEAKER_H
#define SPEAKER_H

#include "target.h"
#include "track.h"


class Speaker {

  public:
  //attr:
//  int defaultVolume; 
 // bool soundsPlaying[2]; // a hard-coded array of the two possible “sounds”: giggle and bo-ing
  bool songsPlaying[3]; // a hard-coded array of the three possible songs (each associated with a single color)
  
  //methods:
  Speaker();
 // int convertPressureToVolume(double pressure); 
 // void playTrack(TrackType trackType, int idx, int vol);
  bool songPlaying();
 // void updateSongs(bool& songEnded);
 // void updateSounds();

};

#endif
