/*
 * IconUpdater.h
 *
 *  Created on: 08/lug/2015
 *      Author: tommasoscarlatti
 */

#ifndef ICONUPDATER_H_
#define ICONUPDATER_H_

#include "MailMsg.h"
#include "MailChecker.h"
#include "IconDrawer.h"

class IconUpdater : private IconDrawer, public Observer {
public:
	IconUpdater(MailChecker * mc) : mailChecker(mc), numUnread(0) {
		mailChecker->subscribe(this);
	};
	~IconUpdater() {
		mailChecker->unsubscribe(this);
	};
	virtual void update(MailMsg* m) {
		if(!(m->getRead())) {
			numUnread++;
		}
		drawIcon(numUnread);
	}
private:
	MailChecker * mailChecker;
	int numUnread;
};

#endif /* ICONUPDATER_H_ */
