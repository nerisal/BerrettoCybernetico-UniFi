/*
 * Shape.h
 *
 *  Created on: 05/lug/2015
 *      Author: davidenesi
 */

#ifndef SHAPE_H_
#define SHAPE_H_

class Shape {
public:
	Shape();
	virtual ~Shape();
	virtual void draw() = 0;
};
#endif /* SHAPE_H_ */
