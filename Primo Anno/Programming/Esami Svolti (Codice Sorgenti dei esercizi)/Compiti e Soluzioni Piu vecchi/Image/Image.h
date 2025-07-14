/*
 * Image.h
 *
 *  Created on: 05/lug/2015
 *      Author: davidenesi
 */

#ifndef IMAGE_H_
#define IMAGE_H_

template<typename T>
class Image {
public:
	Image(int x, int y, int bands, int initValue) :
			_x(x), _y(y), _bands(bands), _initValue(initValue) {
		buffer = new T[x * y];
	}
	virtual ~Image() {
		delete[] buffer;
	}

	const T& getPixel(int x, int y) {
		return buffer[_x * y + x];
	}

	void setPixel (int x, int y, const T& value){
		buffer[x + y*_x]=value;
	}
private:
	int _x, _y, _bands,_initValue;
	T* buffer;
};

#endif /* IMAGE_H_ */
