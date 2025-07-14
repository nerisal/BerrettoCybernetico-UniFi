//
// Created by m3ta on 2/19/2018.
//

#ifndef ADAPTER_VIDEOPLAYER_H
#define ADAPTER_VIDEOPLAYER_H
#include "MediaPlayer.h"
#include "Adapter.h"

class VideoPlayer : public MediaPlayer{
public:
    /*Overriding from the MediaPlayer and having a poointer to the adapter.*/
    virtual void play(string videoType, string fileName) override{
        if(videoType == "avi")
            cout << "VideoPlayer playing AVI..." << endl;
        else if(videoType == "wmv" || videoType == "h246"){
            /*Depetnts from the cideo type our adapter will create the correspodended video player*/
            adapter = new Adapter(videoType);
            adapter->play(videoType, fileName);
        }
        else
            std::cerr << "Unknown file format..." << endl;
    }
private:
    Adapter* adapter;
};


#endif //ADAPTER_VIDEOPLAYER_H
