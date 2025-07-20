/*
 * MsgCenter.h
 *
 *  Created on: 08/lug/2015
 *      Author: tommasoscarlatti
 */

#ifndef MSGCENTER_H_
#define MSGCENTER_H_

#include <iostream>
#include <string>
#include <sstream>
#include "MsgDrawer.h"
#include "MailChecker.h"
#include "MailMsg.h"



class MsgCenter : private MsgDrawer , public Observer {
public:
	MsgCenter(MailChecker * mc) : mailChecker(mc), messageNumber(0) {
		mailChecker->subscribe(this);
	};
	~MsgCenter() {
		mailChecker->unsubscribe(this);
	}
	void update(MailMsg* m) {
		fileName = m->getTitle();
		messageNumber++;
		drawMsg(fileName,numberToString(messageNumber));
	}

	template <typename T>
	std::string numberToString(T Number) {
		std::ostringstream ss;
		ss << Number;
		return ss.str();
	}

private:
	MailChecker * mailChecker;
	int messageNumber;
	std::string fileName;
};

#endif /* MSGCENTER_H_ */
