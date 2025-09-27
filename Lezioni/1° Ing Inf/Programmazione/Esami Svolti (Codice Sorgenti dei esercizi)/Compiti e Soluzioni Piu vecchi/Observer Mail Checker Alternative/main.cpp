/*
 * main.cpp
 *
 *  Created on: 08/lug/2015
 *      Author: tommasoscarlatti
 */
#include <iostream>
#include "MailMsg.h"
#include "MailChecker.h"
#include "IconUpdater.h"
#include "MsgCenter.h"

int main() {

	MailChecker * mailChecker = new MailChecker;               // concrete subject
	MsgCenter * msgCenter = new MsgCenter(mailChecker);        // concrete observer
	IconUpdater * iconUpdater = new IconUpdater(mailChecker);  // concrete observer

	MailMsg * messageA = new MailMsg("First Message", false);
	MailMsg * messageB = new MailMsg("Second Message", true);
	MailMsg * messageC = new MailMsg("Third Message", false);

	mailChecker->addMail(*messageA);
	std::cout << std::endl;
	mailChecker->addMail(*messageB);
	std::cout << std::endl;
	mailChecker->addMail(*messageC);
}

