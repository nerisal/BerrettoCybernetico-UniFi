/*
 * Rectangle.h
 *
 *  Created on: 05/lug/2015
 *      Author: davidenesi
 */

#ifndef RECTANGLE_H_
#define RECTANGLE_H_

class Rectangle: public Shape {
public:
	Rectangle();
	virtual ~Rectangle();
	virtual void draw() {
		//do something
	}
};

#endif /* RECTANGLE_H_ */
