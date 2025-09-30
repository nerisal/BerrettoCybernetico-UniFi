#ifndef SMARTPHONE_H
#define SMARTPHONE_H
#include "Button.h"
#include "ButtonTablet.h"
#include "PanelSmartphone.h"
#include "ButtonSmartphone.h"
#include "AbstractFactory.h"
#include <string>
#include <iostream>
using namespace std;

class Smartphone : public AbstractFactory {
public:

    Smartphone(string n, int x, int y) : _n(n), _x(x), _y(y){
    }

    Button* createButton(){
        cout<<"Creo un bottone per Smartphone"<<endl;
        Button* bs = new ButtonSmartphone(_n, _x, _y);
        return bs;

    }

    Panel* createPanel() {

        cout<<"Creo un pannello per Smartphone"<<endl;
        Panel* b = new PanelSmartphone(_n, _x, _y);
        return b;
    }



private:
    string _n;
    int _x;
    int _y;


};


#endif
