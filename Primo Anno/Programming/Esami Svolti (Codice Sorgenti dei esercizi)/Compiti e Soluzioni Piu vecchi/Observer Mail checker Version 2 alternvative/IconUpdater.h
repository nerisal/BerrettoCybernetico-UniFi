/*
 * IconUpdater.h
 *
 *  Created on: 08/lug/2015
 *      Author: davidenesi
 */

#ifndef ICONUPDATER_H_
#define ICONUPDATER_H_

#include <iostream>
#include <string>
#include "MailMsg.h"
#include "IconDrawer.h"
#include "MailChecker.h"

class IconUpdater: private IconDrawer, public Observer {
public:

	IconUpdater(Subject* myMailChecker) :
			mailChecker(myMailChecker) {
		notRead = 0;
		mailChecker->subscribe(this);
	}
	virtual ~IconUpdater() {
		mailChecker->unSubscribe(this);
	}
	virtual void update(MailMsg m, int k) {
		lastMail = m;
		notRead = k;
		drawIcon(notRead);
	}

private:
	Subject* mailChecker;
	MailMsg lastMail;
	int notRead;
};

#endif /* ICONUPDATER_H_ */
