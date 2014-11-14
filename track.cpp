#include "track.h"


Track::Track(int inDuration)
  : isPlaying(false), duration(inDuration) {}

  
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