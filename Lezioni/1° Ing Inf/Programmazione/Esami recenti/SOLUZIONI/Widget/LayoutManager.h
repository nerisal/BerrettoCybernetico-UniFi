//
// Created by m3ta on 2/19/2018.
//

#ifndef WIDGET_LAYOUTMANAGER_H
#define WIDGET_LAYOUTMANAGER_H
#include "Widget.h"
#include "Button.h"
#include "TextArea.h"

class LayoutManager : public Widget {
public:
    /*Passing our iterator from the list of elements anc for each stored element to the list
     * calling the draw function.*/
     virtual void draw() override {
        for(list<Widget*>::iterator itr = elements.begin(); itr != elements.end(); ++itr)
            (*itr)->draw();
    }
    /*Addding widget with the push back function to the list of elements*/
    void addWidget(Widget* w){
        elements.push_back(w);
    }
    /*Removing  widget with the remove function from the list of elements*/
    void removeWidget(Widget* w){
        elements.remove(w);
    }
private:
    /*Creating a list type o widget to store the elements inside. So we are able to store
     * buttons and text areas because the are related types.*/
    list<Widget*> elements;
};


#endif //WIDGET_LAYOUTMANAGER_H
