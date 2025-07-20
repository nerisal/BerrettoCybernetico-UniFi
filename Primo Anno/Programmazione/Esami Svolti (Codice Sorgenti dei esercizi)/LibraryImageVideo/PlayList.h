//
// 
//

#ifndef LIBRARYIMAGEVIDEO_PLAYLIST_H
#define LIBRARYIMAGEVIDEO_PLAYLIST_H

#include "header.h"

#include "Video.h"
#include "Image.h"
#include "Audio.h"

class PlayList {
public:
    PlayList(Audio audio) : _audio(audio){}
    void play(){
        cout << "\t\t\tPlayList Library" << endl;
        cout << "\t\t\t----------------" << endl;
        _audio.playAudio();
        for(auto itr : _imageList){
            itr.displayImage();
        }
        for(auto itr : _videoList){
            itr.displayVideo();
        }
    }

    void addImage(const Image& newImage){
        _imageList.push_back(newImage);
    }
    void addVideo(const Video& newVideo){
        _videoList.push_back(newVideo);
    }



private:
    list<Video> _videoList;
    list<Image> _imageList;
    bool _playAudio;
    Audio _audio;
};


#endif //LIBRARYIMAGEVIDEO_PLAYLIST_H
