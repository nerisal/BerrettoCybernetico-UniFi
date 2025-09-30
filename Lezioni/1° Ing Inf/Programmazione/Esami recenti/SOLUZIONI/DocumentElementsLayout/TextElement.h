//
// Created by m3tamanj
//

#ifndef DOCUMENTELEMENTSLAYOUT_TEXTELEMENT_H
#define DOCUMENTELEMENTSLAYOUT_TEXTELEMENT_H

#include "DocumentElement.h"

class TextElement : public DocumentElement{
public:
    TextElement(string t) : _text(t){}

    virtual void draw() override {
        cout << "Drawing text element..." << endl;
    }

private:
    string _text;
    int _fontSize;
};


#endif //DOCUMENTELEMENTSLAYOUT_TEXTELEMENT_H
