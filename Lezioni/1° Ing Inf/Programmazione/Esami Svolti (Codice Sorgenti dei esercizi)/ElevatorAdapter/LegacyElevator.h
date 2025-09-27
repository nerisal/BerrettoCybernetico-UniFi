/*
 * LegacyElevator.h
 *
 *  Created on: 13 set 2016
 *      Author: silver III
 */

#ifndef LEGACYELEVATOR_H_
#define LEGACYELEVATOR_H_

class LegacyElevator {
public:
	LegacyElevator(){
		current_level = 0;
		doors_open = false;
	}
	int get_current_level() const;
	void move_by(int level);
	void open_doors();
	void close_doors();

private:
	int current_level;
	bool doors_open;
};

#endif /* LEGACYELEVATOR_H_ */
