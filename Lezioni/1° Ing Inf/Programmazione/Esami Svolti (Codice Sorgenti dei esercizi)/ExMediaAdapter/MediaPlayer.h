//
// Created by Monica Eron on 19/02/18.
//

#ifndef ES6_MEDIAADAPTER_MEDIAPLAYER_H
#define ES6_MEDIAADAPTER_MEDIAPLAYER_H

#include <iostream>
#include <cstring>

class MediaPlayer{
public:
    virtual void play(std::string videotype, std::string filename)=0;
};

#endif //ES6_MEDIAADAPTER_MEDIAPLAYER_H
