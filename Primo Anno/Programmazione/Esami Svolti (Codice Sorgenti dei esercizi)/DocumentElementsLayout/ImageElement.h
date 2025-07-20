//
// Created by m3tamanj
//

#ifndef DOCUMENTELEMENTSLAYOUT_IMAGEELEMENT_H
#define DOCUMENTELEMENTSLAYOUT_IMAGEELEMENT_H

#include "DocumentElement.h"

class ImageElement : public DocumentElement{
public:
    ImageElement(string f) : _fileName(f) {}

    virtual void draw() override {
        cout << "Drawing image element..." << endl;
    }

private:
    string _fileName;
    int _weight, _height;

};


#endif //DOCUMENTELEMENTSLAYOUT_IMAGEELEMENT_H
