#ifndef PANEL_H
#define PANEL_H
#include <iostream>
#include <string>

using namespace std;

class Panel{
public:
    Panel(string name, int w, int h) : text(name), width(w), height(h){

    }

    virtual ~Panel() {
    }

    virtual void draw() = 0;

    string getName()
    {
        return text;
    }

    void setName(string n)
    {
        text = n;
    }


private:
    string text;
    int width;
    int height;


};

#endif
