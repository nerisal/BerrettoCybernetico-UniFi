/*
 * main.cpp
 *
 *  Created on: 05/lug/2015
 *      Author: davidenesi
 */

#include <iostream>
#include <vector>
#include "Shape.h"
#include "Triangle.h"
#include "Rectangle.h"
using namespace std;
int main() {
	vector<Shape*> shapes;
	Triangle* aT = new Triangle;
	Rectangle* aR = new Rectangle;
	shapes.push_back(aT);
	shapes.push_back(aR);
	vector<Shape*>::const_iterator itr;
	for (itr = shapes.begin(); itr != shapes.end(); itr++ )
	(*itr)->draw();
	return 0;
}
