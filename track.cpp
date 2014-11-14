#include "track.h"


Track::Track()
  : isPlaying(false), duration(SOUND_DURATION) {}

  
void Track::startTrack() {
  time(startTime);
  isPlaying = true;
}

void Track::updateIsPlaying() {
  if (isPlaying) {
    time_t now;
    time(&now);
    if (duration <= difftime(now, startTime)) {
      isPlaying = false;
    }
  }
}