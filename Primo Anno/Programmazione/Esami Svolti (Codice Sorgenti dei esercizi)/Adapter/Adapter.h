//
// Created by m3ta on 2/19/2018.
//

#ifndef ADAPTER_ADAPTER_H
#define ADAPTER_ADAPTER_H
#include "MediaPlayer.h"
#include "AdvancedMediaPlayer.h"
#include "H246Player.h"
#include "WMVPlayer.h"

class Adapter : public MediaPlayer{
public:
    /*Passing video type to adapter parametes so depends the type the corresponded object will be created.*/
    Adapter(string videoType){
        if(videoType == "h246")
            amp = new H246Player;
        else if(videoType == "wmv")
            amp = new WMVPlayer;
    }
    /*Depending from the video type we insert it's playing the corresponded video player.*/
    virtual void play(string videoType, string fileName) override {
        if(videoType == "h246")
            amp->videoPlay(fileName, true);
        else if(videoType == "wmv")
            amp->videoPlay(fileName, true);
    }
private:
    /*Pointer to the advancedMediaPlayer for beeing able to create the corresponded object to the constructor. We also taking access
      to the videoplay function.*/
    AdvancedMediaPlayer* amp;
};


#endif //ADAPTER_ADAPTER_H
