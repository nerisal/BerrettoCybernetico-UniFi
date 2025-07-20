//
// Created by m3tamanj
//

#ifndef DOCUMENTELEMENTSLAYOUT_LAYOUTELEMENT_H
#define DOCUMENTELEMENTSLAYOUT_LAYOUTELEMENT_H

#include "DocumentElement.h"

class LayoutElement : public DocumentElement{
public:
    virtual void draw() override {
        for(list<DocumentElement*>::iterator itr = _elements.begin(); itr != _elements.end(); ++itr){
            (*itr)->draw();
        }
    }
    void addElement(DocumentElement* d){
        _elements.push_back(d);
    }
    void removeElement(DocumentElement* d){
        _elements.push_back(d);
    }

private:
    list<DocumentElement*> _elements;

};


#endif //DOCUMENTELEMENTSLAYOUT_LAYOUTELEMENT_H
