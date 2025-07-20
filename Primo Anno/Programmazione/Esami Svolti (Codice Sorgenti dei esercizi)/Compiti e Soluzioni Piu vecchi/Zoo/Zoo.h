/*
 * Zoo.h
 *
 *  Created on: 05/lug/2015
 *      Author: davidenesi
 */

#ifndef ZOO_H_
#define ZOO_H_

#include <vector>
struct Animal {
	int _X;
};

class Zoo {
public:
	const Animal& getAnimals(int k)const{

		return _animals[k];
	}

void setAnimals(const std::vector<Animal>& animals) {
	_animals = animals;
}

private:
	std::vector<Animal> _animals;
};

#endif /* ZOO_H_ */
