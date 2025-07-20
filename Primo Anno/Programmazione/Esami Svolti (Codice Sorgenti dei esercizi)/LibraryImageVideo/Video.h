//
// 
//

#ifndef LIBRARYIMAGEVIDEO_VIDEO_H
#define LIBRARYIMAGEVIDEO_VIDEO_H

#include "header.h"

class Video {
public:
    Video(string videoName,  int videoDim, int videoDur) : _videoName(videoName), _videoDim(videoDim), _videoDur(videoDur) {}

    void displayVideo(){
        cout << "[VIDEO NAME]: " << _videoName << " [VIDEO DIMENSION]: " << _videoDim << " [VIDEO DURATION]: " << _videoDur << endl;
    }
private:
    string _videoName;
    int _videoDim, _videoDur;
};


#endif //LIBRARYIMAGEVIDEO_VIDEO_H
