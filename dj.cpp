#include "dj.h"



void DJ::determineSong(LightCombo currBlinkCombo) {
    if (soundModeOn) {
        int track_idx = currBlinkCombo.getTrackIndex();
        switch (track_idx) {
            case 0:
                Serial.println("PLAY RED"); //222
                break;
            case 1:
                Serial.println("PLAY BLUE"); //333
                break;
            case 2:
                Serial.println("PLAY GREEN"); //444
        }
    }
}

// void DJ::adjustVolume(LightCombo currBlinkCombo, const Target targets[]) {
  
//     int target1_idx = currBlinkCombo.target1Index;
    
//     double pressure = targets[target1_idx].resistanceReadings[sizeMemArray-1] -
//                         targets[target1_idx].baselineRes;
     
//     int new_vol = speaker.convertPressureToVolume(pressure);
    
//     //this will send the new volume, but in order to specify that it is just increasing
//     // the volume for a second and not restarting a track, the second parameter should be -1
//     speaker.playTrack(Song, -1, new_vol);
    
// }

void DJ::determineSound(Target targets[]) {
    if (soundModeOn) {
        //we can play at most 1 giggle and 1 bo'ing at a time
        for(int i = 0; i < 8; i++) {
            //play giggle if soft touch
            if (targets[i].touched) {
               Serial.println("Giggle"); //123

        // Serial.println(targets[i].baselineRes);
        // String str1 = "target [";
        // String str2 = str1 + i;
        // String str3 = str2 + "]: " + targets[i].resistanceReadings[0]+ targets[i].resistanceReadings[1]+ targets[i].resistanceReadings[2];
        // Serial.println(str3);
            }

            //play bo'ing if stretch
            if(targets[i].stretched) {
               Serial.println("Bo'ing"); //321


        // Serial.println(targets[i].baselineRes);
        // String str1 = "target [";
        // String str2 = str1 + i;
        // String str3 = str2 + "]: " + targets[i].resistanceReadings[0]+ targets[i].resistanceReadings[1]+ targets[i].resistanceReadings[2];
        // Serial.println(str3);
            }
        }  
    }   
}
