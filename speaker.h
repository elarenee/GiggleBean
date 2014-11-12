#ifndef SPEAKER_H
#define SPEAKER_H

enum TrackType {Sound, Song};

class Track {

//attr:  
public:
  bool isPlaying;
  (int/double/timestamp??) startTime; // when the song/sound began playing 
  int duration; // how long the song/sound will play (in seconds)
  
  //method:
  void setStartTime();
  
};

class Speaker {

  //attr:
  int defaultVolume; 
  int additionalVolume; 
  Sound sounds[2]; // a hard-coded array of the two possible “sounds”: giggle and bo-ing
  Sound songs[3]; // a hard-coded array of the three possible songs (each associated with a single color)
  
  //methods:
  void setVolume();
  void playTrack(int trackId);
  void stopPlayingTrack();
  bool songPlaying();

};

#endif
