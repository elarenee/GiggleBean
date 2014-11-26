#include "track.h"

Track::Track(double in_duration) {

  duration = in_duration;
  isPlaying = false;
  startTime = 0.0;
  
}

void Track::startTrack() {
  startTime = millis();
  isPlaying = true;
}

bool Track::updateIsPlaying() {
  if (isPlaying) {
    unsigned long now = millis();
    
    if (duration <= now - startTime) {
      isPlaying = false;
      Serial.println("returning true");
      return true; //returns that the song just ended
    }
  }
        Serial.println("returning false");

  return false; //the song did not just end
}
