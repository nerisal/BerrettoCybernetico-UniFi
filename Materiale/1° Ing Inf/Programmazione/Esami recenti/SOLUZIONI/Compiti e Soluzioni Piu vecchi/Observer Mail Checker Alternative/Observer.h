/*
 * Observer.h
 *
 *  Created on: 08/lug/2015
 *      Author: tommasoscarlatti
 */

#ifndef OBSERVER_H_
#define OBSERVER_H_

#include "MailMsg.h"

class Observer {
public:
	virtual ~Observer() {};
	virtual void update(MailMsg* m) = 0;
};




#endif /* OBSERVER_H_ */
