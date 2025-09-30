/*
 * RGBPixel.h
 *
 *  Created on: 05/lug/2015
 *      Author: davidenesi
 */

#ifndef RGBPIXEL_H_
#define RGBPIXEL_H_

class RGBPixel {
public:
	RGBPixel() {
		_R = _G = _B = 100;
	}
	;
	int getR() {
		return _R;
	}
	;
	int getG() {
		return _G;
	}
	;
	int getB() {
		return _B;
	}
	;
	void setR(int R) {
		_R = R;
	}
	;
	void setG(int G) {
		_G = G;
	}
	;
	void setB(int B) {
		_B = B;
	}
	;
private:
	int _R;
	int _G;
	int _B;
};

#endif /* RGBPIXEL_H_ */
