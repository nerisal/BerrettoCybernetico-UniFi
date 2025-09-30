/*
 * NetworkOperationPercentViewer.h
 *
 *  Created on: 05/lug/2015
 *      Author: tommasoscarlatti
 */

#ifndef NETWORKOPERATIONPERCENTVIEWER_H_
#define NETWORKOPERATIONPERCENTVIEWER_H_

#include <iostream>
#include "Observer.h"
#include "NetworkOperation.h"

// CONCRETE OBSERVER

class NetworkOperationPercentViewer: public Observer {
public:
	NetworkOperationPercentViewer(NetworkOperation* n) :
			curr(0), net(n) {
		net->subscribe(this);
	}
	virtual ~NetworkOperationPercentViewer() {
		net->unsubscribe(this);
	}
	;
	virtual void update(int downloaded) {
		curr = downloaded;
	}
	virtual void display() {
		std::cout << "Current = " << curr << std::endl;
	}

private:
	int curr;
	NetworkOperation* net;

};

#endif /* NETWORKOPERATIONPERCENTVIEWER_H_ */
