/*
 * Observer.h
 *
 *  Created on: 05/lug/2015
 *      Author: davidenesi
 */

#ifndef OBSERVER_H_
#define OBSERVER_H_

class Observer {
public:
	virtual void upadte(int X,int Y, int channels,float transp)=0;
protected:
	virtual ~Observer()=0{};
};

#endif /* OBSERVER_H_ */
