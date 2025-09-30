/*
 * NetworkOperationViewer.h
 *
 *  Created on: 05/lug/2015
 *      Author: tommasoscarlatti
 */

#ifndef NETWORKOPERATIONVIEWER_H_
#define NETWORKOPERATIONVIEWER_H_

#include <iostream>
#include "Observer.h"
#include "NetworkOperation.h"

// CONCRETE OBSERVER

class NetworkOperationViewer: public Observer {
public:
	NetworkOperationViewer(NetworkOperation* n) :
			curr(0), net(n) {
		net->subscribe(this);
	}
	virtual ~NetworkOperationViewer() {
		net->unsubscribe(this);
	}
	;
	virtual void update(int downloaded) {
		curr = downloaded;
	}
	virtual void display() {
		std::cout << "Current percentage = " << (curr * 100) / net->getTotal()
				<< std::endl;
	}

private:
	int curr;
	NetworkOperation* net;

};

#endif /* NETWORKOPERATIONVIEWER_H_ */
