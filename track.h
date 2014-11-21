#ifndef TRACK_H
#define TRACK_H

#include <Arduino.h>

#define SOUND_DURATION 2

enum TrackType {Sound, Song};

class Track {
 
public:
  Track();
  void startTrack(); // makes isPlaying true, sets start time
  bool updateIsPlaying(); // returns if track just ended (needed only for songs, ignored by sounds)
  											// and adjusts isPlaying if applicable

  bool isPlaying;
  unsigned long startTime; // when the song/sound began playing 
  unsigned long duration; // how long the song/sound will play (in seconds)
  
};

#endif
