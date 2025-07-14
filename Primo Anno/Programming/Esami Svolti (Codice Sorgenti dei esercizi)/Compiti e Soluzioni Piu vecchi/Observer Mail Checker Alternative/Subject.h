/*
 * Subject.h
 *
 *  Created on: 08/lug/2015
 *      Author: tommasoscarlatti
 */

#ifndef SUBJECT_H_
#define SUBJECT_H_

#include "Observer.h"

class Subject {
public:
	virtual void subscribe(Observer* o) = 0;
	virtual void unsubscribe(Observer* o) = 0;
	virtual void notify(MailMsg * m) = 0;
protected:
	virtual ~Subject() {};
	Subject() {};
};




#endif /* SUBJECT_H_ */
