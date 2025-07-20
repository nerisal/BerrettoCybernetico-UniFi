/*
 * Elevator.h
 *
 *  Created on: 13 set 2016
 *      Author: silver III
 */

#ifndef ELEVATOR_H_
#define ELEVATOR_H_

class Elevator {
public:
	virtual void move_to(int level) = 0;
	virtual void open_doors() = 0;
	virtual void close_doors() = 0;
	virtual ~Elevator() {}
};

#endif /* ELEVATOR_H_ */
