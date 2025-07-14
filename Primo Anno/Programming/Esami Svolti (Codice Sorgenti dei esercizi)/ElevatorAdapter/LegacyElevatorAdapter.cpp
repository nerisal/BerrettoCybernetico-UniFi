/*
 * LegacyElevatorAdapter.cpp
 *
 *  Created on: 13 set 2016
 *      Author: silver III
 */

#include "LegacyElevatorAdapter.h"
#include <iostream>

void LegacyElevatorAdapter::open_doors() {
	LegacyElevator::open_doors();
}

void LegacyElevatorAdapter::close_doors() {
	LegacyElevator::close_doors();
}

void LegacyElevatorAdapter::move_to(int level) {
	LegacyElevator::move_by(level-LegacyElevator::get_current_level());
	std::cout << "Siamo al piano: " << LegacyElevator::get_current_level() << std::endl;
}
