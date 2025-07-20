/*
 * Dwarf.h
 *
 *  Created on: 05/lug/2015
 *      Author: davidenesi
 */

#ifndef DWARF_H_
#define DWARF_H_
#include "Player.h"

class Dwarf: public Player {
public:
	Dwarf(string name):Player(name){};
	virtual ~Dwarf();
	virtual void fight(){
		//do something
	}
};

#endif /* DWARF_H_ */
