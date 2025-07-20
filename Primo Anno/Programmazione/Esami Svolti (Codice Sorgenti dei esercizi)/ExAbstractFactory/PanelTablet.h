#ifndef PANELTABLET_H
#define PANELTABLET_H

#include "Panel.h"
#include <iostream>
#include <string>

using namespace std;


class PanelTablet : public Panel{
public:
    PanelTablet(string s, int w, int h) : Panel(s, w, h){
    }

    virtual ~PanelTablet(){
    }

    virtual void draw(){
        cout<<"Panel per Tablet"<<endl;


    }


};

#endif
