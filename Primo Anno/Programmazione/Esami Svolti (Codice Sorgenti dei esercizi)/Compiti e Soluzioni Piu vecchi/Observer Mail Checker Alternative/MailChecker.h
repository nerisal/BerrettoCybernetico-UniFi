/*
 * MailChecker.h
 *
 *  Created on: 08/lug/2015
 *      Author: tommasoscarlatti
 */

#ifndef MAILCHECKER_H_
#define MAILCHECKER_H_

#include "Subject.h"
#include "MailMsg.h"
#include <vector>
#include <list>

class MailChecker : public Subject {
public:
	void addMail(MailMsg m) {
		mails.push_back(m);
		notify(&m);
	}

	void subscribe(Observer* o) {
		observers.push_back(o);
	}

	void unsubscribe(Observer* o) {
		observers.remove(o);
	}

	void notify(MailMsg * m) {
		for(std::list<Observer*>::iterator itr = observers.begin(); itr != observers.end(); itr++)
			(*itr)->update(m);
	}

	std::vector<MailMsg> mails;
	std::list<Observer*> observers;
};

#endif /* MAILCHECKER_H_ */
