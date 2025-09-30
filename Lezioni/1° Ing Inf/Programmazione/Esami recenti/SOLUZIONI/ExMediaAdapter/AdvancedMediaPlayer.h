//
// Created by Monica Eron on 19/02/18.
//

#ifndef ES6_MEDIAADAPTER_ADVANCEDMEDIAPLAYER_H
#define ES6_MEDIAADAPTER_ADVANCEDMEDIAPLAYER_H

#include<iostream>
#include <cstring>

class AdvancedMediaPlayer{
public:
    virtual void videoplay(std::string filename, bool checkDRM)=0;
};

#endif //ES6_MEDIAADAPTER_ADVANCEDMEDIAPLAYER_H
