#ifndef TABLET_H
#define TABLET_H
#include "Button.h"
#include "ButtonTablet.h"
#include "Panel.h"
#include "PanelTablet.h"
#include "ButtonSmartphone.h"
#include "AbstractFactory.h"
#include <string>
#include <iostream>
using namespace std;

class Tablet : public AbstractFactory {
public:

    Tablet(string n, int x, int y) : _n(n), _x(x), _y(y){
    }

    Button* createButton(){
        cout<<"Creo un bottone per Tablet"<<endl;
        Button* bs = new ButtonTablet(_n, _x, _y);
        return bs;

    }

    Panel* createPanel() {

        cout<<"Creo un pannello per Tablet"<<endl;
        Panel* b = new PanelTablet(_n, _x, _y);
        return b;
    }

private:
    string _n;
    int _x;
    int _y;


};

#endif
