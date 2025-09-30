//
// Created by Monica Eron on 19/02/18.
//

#ifndef ES6_MEDIAADAPTER_VIDEOPLAYER_H
#define ES6_MEDIAADAPTER_VIDEOPLAYER_H

#include <iostream>
#include <cstring>
#include "MediaPlayer.h"
#include "MediaAdapter.h"

class VideoPlayer: public MediaPlayer{
public:
    virtual void play(std::string videotype, std::string filename){
        if(videotype!="avi")
            video->MediaAdapter::play(videotype,filename);
        else
            std::cout<<"VideoPlayer playing AVI... "<<std::endl;
    }

private:
    MediaAdapter* video;
};

#endif //ES6_MEDIAADAPTER_VIDEOPLAYER_H
