/*
 * Subject.h
 *
 *  Created on: 05/lug/2015
 *      Author: tommasoscarlatti
 */

#ifndef SUBJECT_H_
#define SUBJECT_H_

#include "NetworkOperation.h"
#include "Observer.h"

class Subject {
public:
	virtual ~Subject() {};
	virtual void subscribe(Observer* n) = 0;
	virtual void unsubscribe(Observer* n) = 0;
	virtual void notify() = 0;
};

#endif /* SUBJECT_H_ */
