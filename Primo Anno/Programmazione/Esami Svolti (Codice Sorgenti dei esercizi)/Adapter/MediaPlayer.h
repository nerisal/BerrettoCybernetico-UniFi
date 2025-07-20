//
// Created by m3ta on 2/19/2018.
//

#ifndef ADAPTER_MEDIAPLAYER_H
#define ADAPTER_MEDIAPLAYER_H

#include "header.h"

/*Creating media player interface*/
class MediaPlayer {
public:
    /*Pure virtual to ensure that the derived class will override this function.*/
    virtual void play(string videoType, string fileName) = 0;
protected:
    virtual ~MediaPlayer(){}
};


#endif //ADAPTER_MEDIAPLAYER_H
