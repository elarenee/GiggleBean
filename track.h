#ifndef TRACK_H
#define TRACK_H

#include <Arduino.h>

#define SOUND_DURATION 2
#define SONG_DURATION 10

enum TrackType {Sound, Song};

class Track {
 
public:
  Track():duration(0){}
  Track(double in_duration);
  void startTrack(); // makes isPlaying true, sets start time
  bool updateIsPlaying(); // returns if track just ended (needed only for songs, ignored by sounds)
  											// and adjusts isPlaying if applicable

  bool isPlaying;
  double startTime; // when the song/sound began playing 
  double duration; // how long the song/sound will play (in seconds)
  
};

#endif
