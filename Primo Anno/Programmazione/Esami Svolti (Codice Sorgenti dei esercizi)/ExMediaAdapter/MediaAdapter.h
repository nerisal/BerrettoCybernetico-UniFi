//
// Created by Monica Eron on 19/02/18.
//

#ifndef ES6_MEDIAADAPTER_MEDIAADAPTER_H
#define ES6_MEDIAADAPTER_MEDIAADAPTER_H

#include <iostream>
#include <cstring>
#include "MediaPlayer.h"
#include "VideoPlayer.h"
#include "H264Player.h"
#include "WMVPlayer.h"

class MediaAdapter : public MediaPlayer, private H264Player, private WMVPlayer {
public:
    void play(std::string videotype, std::string filename) override {
        if (videotype == "h264")
            H264Player::videoplay(filename, true);
        else {
            if (videotype == "wmv")
                WMVPlayer::videoplay(filename, true);
            else
                std::cout << "Unknown file format: " << videotype << std::endl;
        }
    }
};

#endif //ES6_MEDIAADAPTER_MEDIAADAPTER_H
