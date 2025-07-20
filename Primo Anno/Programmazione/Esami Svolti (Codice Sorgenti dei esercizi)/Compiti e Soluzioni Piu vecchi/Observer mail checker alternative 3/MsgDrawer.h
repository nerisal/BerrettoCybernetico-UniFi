/*
 * MsgDrawer.h
 *
 *  Created on: 08/lug/2015
 *      Author: davidenesi
 */

#ifndef MSGDRAWER_H_
#define MSGDRAWER_H_
#include <iostream>
#include "Observer.h"
#include "IconUpdater.h"
#include "MailChecker.h"
#include "MailMsg.h"

class MsgDrawer {
public:
	virtual ~MsgDrawer() {}

	void drawMsg(std::string msg, std::string iconName) {
		drawIcon(iconName);
		std::cout << msg << std::endl;
	}
	void drawIcon(std::string filename) {
		std::cout<<"Filename: "<< filename<<std::endl;
	}
};

#endif /* MSGDRAWER_H_ */
