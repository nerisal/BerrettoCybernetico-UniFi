#include "header.h"
#include "Coordinates.h"

int main() {
    Coordinates<double> a(15.5, -8.9);
    Coordinates<double> b(5, 12);
    Coordinates<float> c(-3.38);
    Coordinates<double> d = a+b;
    cout << "Coordinates of point A" << endl;
    a.printCoordinates();

    cout << "Coordinates of point B" << endl;
    b.printCoordinates();

    cout << "Coordinates of point C" << endl;
    c.printCoordinates();

    cout << "Coordinates of copy A + B" << endl;
    d.printCoordinates();



}