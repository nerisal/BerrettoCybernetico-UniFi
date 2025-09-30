#ifndef PANELSMARTPHONE_H
#define PANELSMARTPHONE_H

#include "Panel.h"
#include <iostream>
#include <string>
using namespace std;


class PanelSmartphone : public Panel{
public:
    PanelSmartphone(string s, int w, int h) : Panel(s, w, h){
    }

    virtual ~PanelSmartphone(){
    }

    virtual void draw(){
        cout<<"Panel per Smartphone"<<endl;
    }



};

#endif
