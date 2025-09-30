/*
 * Observer.h
 *
 *  Created on: 06/lug/2015
 *      Author: tommasoscarlatti
 */

#ifndef OBSERVER_H_
#define OBSERVER_H_

class Observer {
public:
	virtual ~Observer() {};
	void virtual update(int downloaded) = 0;
	virtual void display() = 0;

};



#endif /* OBSERVER_H_ */
