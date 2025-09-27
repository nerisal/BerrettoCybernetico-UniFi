#ifndef BUTTON_H
#define BUTTON_H
#include <string>
#include <iostream>
using namespace std;

class Button{
public:
    Button(string name, int w, int h) : name(name), width(w), height(h){
    }

    virtual ~Button(){
    }

    virtual void draw(int x, int y) = 0;

    string getName()
    {
        return name;
    }

    void setName(string n)
    {
        name = n;
    }

private:
    string name;
    int width;
    int height;

};

#endif
