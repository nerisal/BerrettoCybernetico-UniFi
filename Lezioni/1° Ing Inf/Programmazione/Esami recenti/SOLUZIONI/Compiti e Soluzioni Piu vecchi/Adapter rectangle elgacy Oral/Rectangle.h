/*
 * Rectangle.h
 *
 *  Created on: 21/lug/2015
 *      Author: Alberrto
 */

#ifndef RECTANGLE_H_
#define RECTANGLE_H_



class Rectangle {
public:
	virtual void draw() const = 0;
	virtual int getULx() const = 0;
	virtual int getULy() const = 0;
	virtual int getBRx() const = 0;
	virtual int getBRy() const = 0;
	virtual ~Rectangle() = 0 {}
};


#endif /* RECTANGLE_H_ */
