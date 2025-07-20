#include <iostream>
#include "Coordinates.h"

using namespace std;

int main() {
    Coordinates<int> c(4,5);
    Coordinates<int> a(2,1);
    Coordinates<float> b(5.4,7.4);
    Coordinates<float> d(102.4, 60.3);

    c=c;

    c.operator+(a);
    //b.operator=(d);
    b=d;
    d.operator+(d);

    c.printCoordinates();
    d.printCoordinates();
    b.printCoordinates();
}