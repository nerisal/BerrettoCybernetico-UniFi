//
// Created by m3ta on 2/19/2018.
//

#ifndef ADAPTER_H246PLAYER_H
#define ADAPTER_H246PLAYER_H
#include "AdvancedMediaPlayer.h"

/*Inheriting from the base class AdvancedMediaPlayer publicaly*/
class H246Player : public AdvancedMediaPlayer{
public:
    /*Overriding the pure virtual function from the base class.*/
    virtual void videoPlay(string fileName, bool checkDRM) override{
        cout << "H246Player playing..." << endl;
    }
};


#endif //ADAPTER_H246PLAYER_H
