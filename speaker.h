#ifndef SPEAKER_H
#define SPEAKER_H

#include "target.h"
#include <time.h>

enum TrackType {Sound, Song};

class Track {

//attr:  
public:
  bool isPlaying;
  time_t startTime; // when the song/sound began playing 
  int duration; // how long the song/sound will play (in seconds)
  
  //method:
  void startTrack(); // makes isPlaying true, sets start time
  void updateIsPlaying(); // returns if track is still playing and adjusts isPlaying if applicable
  
};

class Speaker {

  //attr:
  int defaultVolume; 
  Track sounds[2]; // a hard-coded array of the two possible “sounds”: giggle and bo-ing
  Track songs[3]; // a hard-coded array of the three possible songs (each associated with a single color)
  
  //methods:
  int convertPressureToVolume(int pressure); 
  void playTrack(int vol, int idx, TrackType trackType);
  bool songPlaying();
  void updateSounds(Target[] targetArray);
  bool updateSongs(Target[] targetArray);

};

#endif
