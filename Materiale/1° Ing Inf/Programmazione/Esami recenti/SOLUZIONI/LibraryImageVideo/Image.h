//
// 
//

#ifndef LIBRARYIMAGEVIDEO_IMAGE_H
#define LIBRARYIMAGEVIDEO_IMAGE_H

#include "header.h"

class Image {
public:
    Image(string imageName, int imageDim) : _imageName(imageName), _imageDim(imageDim){}

    void displayImage(){
        cout << "[IMAGE NAME]: " << _imageName << " [IMAGE DIMENSIOM]: " << _imageDim << endl;
    }
private:
    string _imageName;
    int _imageDim;
};


#endif //LIBRARYIMAGEVIDEO_IMAGE_H
