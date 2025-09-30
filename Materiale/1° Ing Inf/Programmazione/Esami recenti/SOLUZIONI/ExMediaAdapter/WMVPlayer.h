//
// Created by Monica Eron on 19/02/18.
//

#ifndef ES6_MEDIAADAPTER_WMVPLAYER_H
#define ES6_MEDIAADAPTER_WMVPLAYER_H

#include <iostream>
#include <cstring>
#include "AdvancedMediaPlayer.h"

class WMVPlayer : public AdvancedMediaPlayer{
public:
    virtual void videoplay(std::string filename, bool chekDRM)override {
        std::cout<<"WMVPlayer playing..."<<std::endl;
    }
};

#endif //ES6_MEDIAADAPTER_WMVPLAYER_H
