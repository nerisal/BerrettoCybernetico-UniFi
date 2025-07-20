//
// Created by m3ta on 2/19/2018.
//

#ifndef ADAPTER_ADVANCEDMEDIAPLAYER_H
#define ADAPTER_ADVANCEDMEDIAPLAYER_H
#include "header.h"

/*Advanced media player interface.*/

class AdvancedMediaPlayer {
public:
    /*Making it pure virtual so the derived class must override it.*/
    virtual void videoPlay(string fileName, bool checkDRM) = 0;
protected:
    virtual ~AdvancedMediaPlayer(){}
};


#endif //ADAPTER_ADVANCEDMEDIAPLAYER_H
