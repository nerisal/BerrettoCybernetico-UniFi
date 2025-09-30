/*
 * Subject.h
 *
 *  Created on: 08/lug/2015
 *      Author: davidenesi
 */

#ifndef SUBJECT_H_
#define SUBJECT_H_
#include "Observer.h"

class Subject {
public:
	virtual void subscribe(Observer* o)=0;
	virtual void unSubscribe(Observer* o)=0;
	virtual void notify()=0;
protected:
	virtual ~Subject();
	Subject(){};


};

#endif /* SUBJECT_H_ */
