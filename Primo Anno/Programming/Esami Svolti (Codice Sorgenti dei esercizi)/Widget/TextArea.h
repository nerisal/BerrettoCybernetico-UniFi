//
// Created by m3ta on 2/19/2018.
//

#ifndef WIDGET_TEXTAREA_H
#define WIDGET_TEXTAREA_H
#include "Widget.h"

class TextArea : public Widget{
public:
    TextArea(string t) : text(t) {}
    /*Just overriding the pure virtual draw function and priting something...*/
    virtual void draw() override{
        cout << "Text area drawing..." << endl;
    }
private:
    string text;
};


#endif //WIDGET_TEXTAREA_H
