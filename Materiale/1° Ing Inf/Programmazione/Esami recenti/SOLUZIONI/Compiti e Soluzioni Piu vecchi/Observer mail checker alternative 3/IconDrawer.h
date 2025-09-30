/*
 * IconDrawer.h
 *
 *  Created on: 08/lug/2015
 *      Author: davidenesi
 */

#ifndef ICONDRAWER_H_
#define ICONDRAWER_H_
#include <iostream>
#include "Observer.h"
#include "IconUpdater.h"
#include "MailChecker.h"
#include "MailMsg.h"

class IconDrawer{
public:
	virtual ~IconDrawer(){}

	void drawIcon(int numUnread){
		std::cout<<"Not read mails: "<<numUnread<<std::endl;
	}

};

#endif /* ICONDRAWER_H_ */
