/*
 * LegacyRectangle.h
 *
 *  Created on: 21/lug/2015
 *      Author: Alberrto
 */

#ifndef LEGACYRECTANGLE_H_
#define LEGACYRECTANGLE_H_

#include<iostream>

class LegacyRectangle {
public:
	LegacyRectangle();
	LegacyRectangle(int ax, int ay, int aw, int ah): x(ax) , y(ay) , w(aw) , h(ah) {};

	void legacyDraw() const {
		std::cout << "legacyDraw x: " << x << " -y:" << y << "-w:" << w << "h:" << h <<std::endl;
	}

	int getH() const {
		return h;
	}

	int getW() const {
		return w;
	}

	int getX() const {
		return x;
	}

	int getY() const {
		return y;
	}

private:
	int x, y, w, h;

};


#endif /* LEGACYRECTANGLE_H_ */
