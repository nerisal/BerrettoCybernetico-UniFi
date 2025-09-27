//
// Created by m3ta on 2/19/2018.
//

#ifndef WIDGET_WIDGET_H
#define WIDGET_WIDGET_H
#include "header.h"

/*Abstract base class for the derived classes.*/
class Widget {
public:
    virtual void draw() = 0;
protected:
    virtual ~Widget(){}
};


#endif //WIDGET_WIDGET_H
