//
// Created by m3ta on 2/19/2018.
//

#ifndef ADAPTER_WMVPLAYER_H
#define ADAPTER_WMVPLAYER_H
#include "AdvancedMediaPlayer.h"

/*Inheriting from the base class AdvancedMediaPlayer publicaly*/
class WMVPlayer : public AdvancedMediaPlayer{
public:
    /*Overriding the pure virtual function from the base class.*/
    virtual void videoPlay(string fileName, bool checkDRM) override{
        cout << "WMVPlayer playing..." << endl;
    }
};


#endif //ADAPTER_WMVPLAYER_H
