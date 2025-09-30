/*
 * main.cpp
 *
 *  Created on: 08/lug/2015
 *      Author: davidenesi
 */

#include <vector>
#include <list>
#include "Subject.h"
#include "MailMsg.h"
#include "Observer.h"
#include "MailChecker.h"
#include "MsgDrawer.h"
#include "IconDrawer.h"
#include "MsgCenter.h"


int main () {

	MailChecker primo;


	MsgCenter alfa(&primo);
	IconUpdater curri(&primo);

	MailMsg mail1("unifi",false);
	MailMsg mail2("proposta di lavoro",true);
	MailMsg mail3("spam brutale",false);
	MailMsg mail4("GoogleEarthTeam",true);

	primo.addMail(mail1);
	std::cout<<std::endl;
	primo.addMail(mail2);
	std::cout<<std::endl;
	primo.addMail(mail3);
	std::cout<<std::endl;
	primo.addMail(mail4);
}
