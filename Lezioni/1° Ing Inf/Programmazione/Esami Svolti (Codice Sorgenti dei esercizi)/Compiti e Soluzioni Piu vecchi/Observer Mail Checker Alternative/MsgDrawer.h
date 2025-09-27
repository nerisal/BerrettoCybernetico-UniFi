/*
 * MsgDrawer.h
 *
 *  Created on: 08/lug/2015
 *      Author: tommasoscarlatti
 */

#ifndef MSGDRAWER_H_
#define MSGDRAWER_H_

#include <iostream>
#include "Observer.h"
#include "MailMsg.h"

class MsgDrawer {
public:
	~MsgDrawer() {};
	void drawMsg(std::string msg, std::string iconName) {
		drawIcon(iconName);
		std::cout << "Title: " << msg << std::endl;
	}
	void drawIcon(std::string fileName) {
		std::cout << "Filename: " << fileName << std::endl;
	}
};




#endif /* MSGDRAWER_H_ */
