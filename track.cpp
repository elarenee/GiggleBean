#include "track.h"

Track::Track()
  : isPlaying(false), duration(SOUND_DURATION) {}

void Track::startTrack() {
  startTime = millis();
  isPlaying = true;
}

void Track::updateIsPlaying() {
  if (isPlaying) {
    unsigned long now = millis();
    
    if (duration >= now - startTime) {
      isPlaying = false;
    }
  }
}
