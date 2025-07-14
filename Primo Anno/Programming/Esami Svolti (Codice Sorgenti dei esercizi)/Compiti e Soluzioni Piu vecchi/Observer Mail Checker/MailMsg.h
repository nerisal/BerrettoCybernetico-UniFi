/*
 * MailMsg.h
 *
 *  Created on: 08/lug/2015
 *      Author: davidenesi
 */

#ifndef MAILMSG_H_
#define MAILMSG_H_
#include <string>

class MailMsg {
public:
	MailMsg(std::string t, bool r=false): title(t), read(r){};
	virtual ~MailMsg();
	std::string getTitle()const{return title;}
	bool isRead() const {return read;}

private:
	std::string title;
	bool read;

};

#endif /* MAILMSG_H_ */
