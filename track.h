#include <DS1307RTC.h>

#include <Wire.h>

#include <Time.h>



#ifndef TRACK_H
#define TRACK_H

#define SOUND_DURATION 2

class Track {
 friend class DJ;
public:
  Track();
  void startTrack(); // makes isPlaying true, sets start time
  void updateIsPlaying(); // returns if track is still playing and adjusts isPlaying if applicable

private:
  bool isPlaying;
  time_t startTime; // when the song/sound began playing 
  double duration; // how long the song/sound will play (in seconds)
  
};

#endif
