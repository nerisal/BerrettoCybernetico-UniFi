/*
 * Widget.h
 *
 *  Created on: 08/lug/2015
 *      Author: davidenesi
 */

#ifndef WIDGET_H_
#define WIDGET_H_

class Widget {
public:
	virtual ~Widget(){};
	virtual void draw()=0;
};

#endif /* WIDGET_H_ */
