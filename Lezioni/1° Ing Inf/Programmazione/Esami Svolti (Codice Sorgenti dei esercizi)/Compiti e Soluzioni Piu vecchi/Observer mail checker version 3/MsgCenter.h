/*
 * MsgCenter.h
 *
 *  Created on: 08/lug/2015
 *      Author: davidenesi
 */

#ifndef MSGCENTER_H_
#define MSGCENTER_H_

#include <iostream>
#include <string>
#include <sstream>
#include "MailMsg.h"
#include "MailChecker.h"
#include "MsgDrawer.h"

class MsgCenter: private MsgDrawer, public Observer {
public:
	MsgCenter(Subject* myMailChecker) :
			mailChecker(myMailChecker), countOfMails(0) {
		notRead = 0;
		mailChecker->subscribe(this);
	}
	virtual ~MsgCenter() {
		mailChecker->unSubscribe(this);
	}
	virtual void update(MailMsg m, int k) {
		lastMail = m;
		notRead = k;
		countOfMails++;
		drawMsg(lastMail.getTitle(), numberToString(countOfMails));
	}

	template<typename T>
	std::string numberToString(T Number) {
		std::ostringstream ss;
		ss << Number;
		return ss.str();
	}

private:
	Subject* mailChecker;
	MailMsg lastMail;
	int countOfMails;
	int notRead;
};

#endif /* MSGCENTER_H_ */
