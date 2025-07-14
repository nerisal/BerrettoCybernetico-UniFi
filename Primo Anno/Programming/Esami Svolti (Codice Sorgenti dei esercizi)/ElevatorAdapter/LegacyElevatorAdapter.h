/*
 * LegacyElevatorAdapter.h
 *
 *  Created on: 13 set 2016
 *      Author: silver III
 */

#ifndef LEGACYELEVATORADAPTER_H_
#define LEGACYELEVATORADAPTER_H_

#include "LegacyElevator.h"
#include "Elevator.h"

class LegacyElevatorAdapter : private LegacyElevator, public Elevator {
public:
	LegacyElevatorAdapter() {
		LegacyElevator();
	}
	virtual void open_doors();
	virtual void close_doors();
	virtual void move_to(int level);
};

#endif /* LEGACYELEVATORADAPTER_H_ */
