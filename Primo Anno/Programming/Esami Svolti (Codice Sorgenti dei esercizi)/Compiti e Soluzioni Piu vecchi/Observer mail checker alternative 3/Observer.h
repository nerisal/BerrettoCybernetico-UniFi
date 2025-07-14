/*
 * Observer.h
 *
 *  Created on: 08/lug/2015
 *      Author: davidenesi
 */

#ifndef OBSERVER_H_
#define OBSERVER_H_
#include "MailMsg.h"

class Observer {
public:
	virtual ~Observer(){}
	virtual void update(MailMsg mail, int notRead)=0;
};

#endif /* OBSERVER_H_ */
