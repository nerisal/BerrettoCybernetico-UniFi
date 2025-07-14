/*
 * LegacyRectangleAdapter.h
 *
 *  Created on: 21/lug/2015
 *      Author: Alberrto
 */

#ifndef LEGACYRECTANGLEADAPTER_H_
#define LEGACYRECTANGLEADAPTER_H_

#include <iostream>
#include "LegacyRectangle.h"
#include "Rectangle.h"

class LegacyRectangleAdapter: public Rectangle, private LegacyRectangle {
private:
	LegacyRectangle * lr;
public:
	LegacyRectangleAdapter(LegacyRectangle * lr) :
			lr(lr) {
	}
	;
	virtual void draw() const {
		std::cout << "rectangledraw x: " << getULx() << " -y:" << getULy() << "-w:" << getBRx() << "h:"
				<< getBRy() << std::endl;
	}
	virtual ~LegacyRectangleAdapter() {
	}
	;

	virtual int getULx() const {
		return LegacyRectangle::getX();
	}
	;
	virtual int getULy() const {
		return LegacyRectangle::getY();
	}
	;
	virtual int getBRx() const {
		return LegacyRectangle::getX() * (LegacyRectangle::getW());
	}
	;
	virtual int getBRy() const {
		return LegacyRectangle::getY() * (LegacyRectangle::getH());
	}
	;

};

#endif /* LEGACYRECTANGLEADAPTER_H_ */
