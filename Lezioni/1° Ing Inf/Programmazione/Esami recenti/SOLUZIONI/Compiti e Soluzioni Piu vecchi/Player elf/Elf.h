/*
 * Elf.h
 *
 *  Created on: 05/lug/2015
 *      Author: davidenesi
 */

#ifndef ELF_H_
#define ELF_H_
#include "Player.h"

class Elf: public Player {
public:
	Elf(string name):Player(name){};
	virtual ~Elf();
	virtual void fight(){
		//do something
	}
};

#endif /* ELF_H_ */
