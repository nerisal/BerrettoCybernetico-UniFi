/*
 * main.cpp
 *
 *  Created on: 21/lug/2015
 *      Author: Alberrto
 */


#include <iostream>
#include "LegacyRectangle.h"
#include "Rectangle.h"
#include "LegacyRectangleAdapter.h"

int main(int argc, char*argv[]){
	LegacyRectangle * legacyrectangle = new LegacyRectangle(1 , 1 , 4 , 5);
	Rectangle *r= new LegacyRectangleAdapter (legacyrectangle);
	r->draw();
}






