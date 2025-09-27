#include "Button.h"
#include "ButtonSmartphone.h"
#include "ButtonTablet.h"
#include "Smartphone.h"
#include <iostream>
#include "AbstractFactory.h"
#include <string>
#include "Tablet.h"

using namespace std;

int main()
{
    bool isTablet = false;

    AbstractFactory* factory;

    if(isTablet){
        factory = new Tablet("Tablet", 5, 4);
    }
    else{

        factory = new Smartphone("Smartphone", 5, 6);
    }

    Panel * p = 0;
    Button * b = 0;

    p = factory->createPanel();
    b = factory->createButton();

    p->draw();
    b->draw(4, 5);

    return 0;
}
