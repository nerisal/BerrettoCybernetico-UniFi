//
// Created by m3ta on 2/19/2018.
//

#ifndef WIDGET_BUTTON_H
#define WIDGET_BUTTON_H
#include "Widget.h"

class Button : public Widget{
public:
    Button(string t) : text(t) {}
    /*Just overriding the pure virtual draw function and priting something...*/
    virtual void draw() override{
        cout << "Drawing button..." << endl;
    }
private:
    string text;
};


#endif //WIDGET_BUTTON_H
