/*
 * MailChecker.h
 *
 *  Created on: 08/lug/2015
 *      Author: davidenesi
 */

#ifndef MAILCHECKER_H_
#define MAILCHECKER_H_

#include <vector>
#include <list>
#include "Subject.h"
#include "MailMsg.h"
#include "Observer.h"

class MailChecker: public Subject {
public:
	MailChecker(){
		lastMail=*(new MailMsg("",true));
		notRead=0;
	}
	virtual ~MailChecker(){}
	std::vector<MailMsg> mails;

	void addMail(MailMsg aMail) {
		mails.push_back(aMail);
		checkNumRead();
		lastMail = aMail;
		notify();
	}
	void checkNumRead() {
		for (std::vector<MailMsg>::const_iterator itr = mails.begin();
				itr != mails.end(); itr++) {
			notRead = 0;
			if (!(*itr).isRead())
				notRead++;
		}
	}

	virtual void notify() {
		for (std::list<Observer*>::const_iterator itr = observers.begin();
				itr != observers.end(); itr++)
			(*itr)->update(lastMail, notRead);
	}
	virtual void subscribe(Observer* o){
		observers.push_back(o);
		notify();
	}
	virtual void unSubscribe(Observer* o){
		observers.remove(o);
	}

	std::list<Observer*> observers;
	MailMsg lastMail;
	int notRead;

};

#endif /* MAILCHECKER_H_ */
