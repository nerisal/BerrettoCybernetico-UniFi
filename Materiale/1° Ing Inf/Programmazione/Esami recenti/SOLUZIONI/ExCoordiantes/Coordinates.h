//
// Created by Monica Eron on 20/02/18.
//

#ifndef COORDINATES_COORDINATES_H
#define COORDINATES_COORDINATES_H

#include <iostream>

using namespace std;

template <typename T>
class Coordinates{
public:
    Coordinates(T x = 0, T y = 0): _x(x), _y(y){}
    ~Coordinates(){}

    void printCoordinates(){
        cout<<"( "<< _x << " ; " << _y << " )" << endl;
    }

    Coordinates operator=(Coordinates& c){
        if( this !=  &c){
            _x = c._x;
            _y = c._y;
            return *this;
        } else
            return *this;
    }

    void operator-(Coordinates& c){
        _x -= c._x;
        _y -= c._y;
    }

    void operator+(Coordinates& c) {
        _x += c._x;
        _y += c._y;
    }

private:
    T _x;
    T _y;
};

#endif //COORDINATES_COORDINATES_H
