#ifndef BUTTONTABLET_H
#define BUTTONTABLET_H

#include "Button.h"
#include <iostream>
#include <string>

using namespace std;


class ButtonTablet : public Button{
public:
    ButtonTablet(string s, int w, int h) : Button(s, w, h){
    }

    virtual ~ButtonTablet(){
    }

    virtual void draw(int x, int y){
        cout<<"Tablet con x: "<<x<<" e y: "<<y<<endl;
    }



};

#endif
