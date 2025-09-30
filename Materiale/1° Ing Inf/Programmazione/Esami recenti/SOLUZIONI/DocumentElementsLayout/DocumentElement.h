//
// Created by m3tamanj
//

#ifndef DOCUMENTELEMENTSLAYOUT_DOCUMENTELEMENT_H
#define DOCUMENTELEMENTSLAYOUT_DOCUMENTELEMENT_H

#include "header.h"

class DocumentElement {
public:
    virtual void draw() = 0;

private:
    int _posX, _poxY;
protected:
    virtual ~DocumentElement() = default;
};


#endif //DOCUMENTELEMENTSLAYOUT_DOCUMENTELEMENT_H
