//
// Created by m3ta on 2/19/2018.
//

#ifndef CARTESIANCOORDINATES_COORDINATES_H
#define CARTESIANCOORDINATES_COORDINATES_H
#include "header.h"

// Class to represent Coordinatess.

/*Defining our class template.*/
template<typename T>
class Coordinates {
public:
    Coordinates(T x = 0.0, T y = 0.0) : _xVal(x), _yVal(y) {}
    /*Creating getters to get the values of coordinates*/
    T getX() const { return _xVal; }
    T getY() const { return _yVal; }

    /*Overloading our two operators.*/
    Coordinates operator+(const Coordinates& c){
        Coordinates coor;
        coor._xVal = this->_xVal + c._xVal;
        coor._yVal = this->_yVal + c._yVal;
        return coor;
    }
    Coordinates operator-(const Coordinates& c){
        Coordinates coor;
        coor._xVal = this->_xVal + c._xVal;
        coor._yVal = this->_yVal + c._yVal;
        return coor;
    }
    Coordinates operator=(const Coordinates& c){
        if(this != &c) {
            _xVal = c._xVal;
            _yVal = c._yVal;
        }
        return* this;
    }
    Coordinates add(Coordinates b) {
        return Coordinates(_xVal + b._xVal, _yVal + b._yVal);
    }
    /*Simple function to print values of our coordinates.*/
    void printCoordinates() {
        cout << "(" << _xVal << "," << _yVal << ")" << endl;
    }

private:
    /*Creating our to private members for the coordinates*/
    T _xVal, _yVal;
};

#endif //CARTESIANCOORDINATES_COORDINATES_H
