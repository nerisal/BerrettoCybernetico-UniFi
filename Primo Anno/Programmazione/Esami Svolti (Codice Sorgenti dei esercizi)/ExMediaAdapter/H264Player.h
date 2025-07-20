//
// Created by Monica Eron on 19/02/18.
//

#ifndef ES6_MEDIAADAPTER_H264PLAYER_H
#define ES6_MEDIAADAPTER_H264PLAYER_H

#include <iostream>
#include <cstring>
#include "AdvancedMediaPlayer.h"

class H264Player : public AdvancedMediaPlayer{
public:
    virtual void videoplay(std::string filename, bool checkDRM)override {
        std::cout<<"H264Player playing..."<<std::endl;
    }
};
#endif //ES6_MEDIAADAPTER_H264PLAYER_H
