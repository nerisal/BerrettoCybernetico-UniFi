/*
 * LegacyElevator.cpp
 *
 *  Created on: 13 set 2016
 *      Author: silver III
 */

#include "LegacyElevator.h"

int LegacyElevator::get_current_level() const {
	return current_level;
}

void LegacyElevator::move_by(int level) {
	current_level += level;
}

void LegacyElevator::open_doors() {
	doors_open = true;
}

void LegacyElevator::close_doors() {
	doors_open = false;
}
