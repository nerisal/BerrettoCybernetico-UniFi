/*
 * Adapter.h
 *
 *  Created on: 05/lug/2015
 *      Author: davidenesi
 */

#ifndef ADAPTER_H_
#define ADAPTER_H_

class Adapter:private RGBPixel,public GrayPixel{
public:
	Adapter();
	virtual ~Adapter();
	virtual unsigned char getPixel(){
		return static_cast<unsigned char>(0.299*_R+0.578*_G+0.114*_B);
	}
};

#endif /* ADAPTER_H_ */
