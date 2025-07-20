/*
 * MailMsg.h
 *
 *  Created on: 08/lug/2015
 *      Author: tommasoscarlatti
 */

#ifndef MAILMSG_H_
#define MAILMSG_H_

#include <iostream>

class MailMsg {
public:
	MailMsg(std::string t, bool r = false) : title(t), read(r) {};
	std::string getTitle() {
		return title;
	}
	bool getRead() {
		return read;
	}

private:
	std::string title;
	bool read;
};

#endif /* MAILMSG_H_ */
