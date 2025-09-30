#include "header.h"
#include "Widget.h"
#include "Button.h"
#include "TextArea.h"
#include "LayoutManager.h"

int main() {
    /*Creating our layout manager and some button and widget functions.*/
    LayoutManager* layoutManager = new LayoutManager;
    LayoutManager* layoutManager2 = new LayoutManager;
    Widget* button = new Button("Button");
    Widget* textArea = new TextArea("Text area");

    /*Adding some widget to our list*/
    layoutManager2->addWidget(button);
    layoutManager2->addWidget(textArea);
    layoutManager->addWidget(layoutManager2);
    /*Drawing any type of widgets...*/
    layoutManager->draw();
    return 0;
}