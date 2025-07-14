/*
 * NetworkOperation.h
 *
 *  Created on: 05/lug/2015
 *      Author: tommasoscarlatti
 */

#ifndef NETWORKOPERATION_H_
#define NETWORKOPERATION_H_

#include "Subject.h"
#include "Observer.h"
#include <list>

// CONCRETE SUBJECT

class NetworkOperation : public Subject {
public:
	NetworkOperation(int total, int current = 0) : _total(total), _current(current) {};
	virtual ~NetworkOperation() {};

	virtual void updateOperations(int processed) {
		_current = processed;
		notify();
	}

	void notify() {
		for(std::list<Observer*>::iterator itr = observers.begin(); itr != observers.end(); itr++) {
			(*itr)->update(_current);
		}
	}

	virtual void subscribe(Observer* n) {
		observers.push_back(n);
	}

	virtual void unsubscribe(Observer* n) {
		observers.remove(n);
	}

	int getCurrent() const {
		return _current;
	};
	int getTotal() const {
		return _total;
	};


private:
	std::list<Observer*> observers;
	int _total;
	int _current;
};

#endif /* NETWORKOPERATION_H_ */
