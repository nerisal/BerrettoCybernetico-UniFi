/*
 * Image2D.h
 *
 *  Created on: 05/lug/2015
 *      Author: davidenesi
 */

#ifndef IMAGE2D_H_
#define IMAGE2D_H_
#include "GrayPixel.h"
#include "RGBPixel.h"

template <typename T>
class Image2D {
public:
	Image2D(int X, int Y);
	virtual ~Image2D();

	int getPixel(const T& j);



private:
	int X,Y;
};

#endif /* IMAGE2D_H_ */
