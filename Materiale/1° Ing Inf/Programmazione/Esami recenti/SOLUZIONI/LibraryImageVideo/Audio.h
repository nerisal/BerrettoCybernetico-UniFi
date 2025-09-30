//
// 
//

#ifndef LIBRARYIMAGEVIDEO_AUDIO_H
#define LIBRARYIMAGEVIDEO_AUDIO_H

#include "header.h"

class Audio {
public:
    Audio(string audioName, int audioDuration) : _audioName(audioName), _audioDuration(audioDuration) {}

    void playAudio(){
            cout << "Playing " << _audioName << "..." << endl;
    }



private:
    string _audioName;
    int _audioDuration;

};


#endif //LIBRARYIMAGEVIDEO_AUDIO_H
