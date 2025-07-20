/*
 * IconDrawer.h
 *
 *  Created on: 08/lug/2015
 *      Author: tommasoscarlatti
 */

#ifndef ICONDRAWER_H_
#define ICONDRAWER_H_

class IconDrawer {
public:
	~IconDrawer() {};
	void drawIcon(int numUnread) {
		std::cout << "Unread messages: " << numUnread << std::endl;
	}
};

#endif /* ICONDRAWER_H_ */
