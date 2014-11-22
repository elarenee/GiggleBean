#include "track.h"


Track::Track()
  : isPlaying(false), duration(SOUND_DURATION) {}

void Track::startTrack() {
  startTime = millis();
  isPlaying = true;
}

bool Track::updateIsPlaying() {
  if (isPlaying) {
    unsigned long now = millis();
    
    if (duration >= now - startTime) {
      isPlaying = false;
      return true; //returns that the song just ended
    }
  }
  return false; //the song did not just end
}
