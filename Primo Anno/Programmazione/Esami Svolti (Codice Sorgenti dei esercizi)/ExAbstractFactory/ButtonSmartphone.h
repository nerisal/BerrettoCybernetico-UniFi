#ifndef BUTTONSMARTPHONE_H
#define BUTTONSMARTPHONE_H

#include "Button.h"
#include <iostream>
#include <string>
using namespace std;


class ButtonSmartphone : public Button{
public:
    ButtonSmartphone(string s, int w, int h) : Button(s, w, h){
    }

    virtual ~ButtonSmartphone(){
    }

    virtual void draw(int x, int y){
        cout<<"Smartphone con x: "<<x<<" e y: "<<y<<endl;

    }



};

#endif
