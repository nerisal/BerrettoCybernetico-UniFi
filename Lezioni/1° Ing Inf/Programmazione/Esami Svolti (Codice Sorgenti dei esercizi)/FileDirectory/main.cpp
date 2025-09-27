/*
 * main.cpp
 *
 *  Created on: 12 gen 2017
 *      Author: silver III
 */

#include <typeinfo>
#include "Directory.h"

int main () {

	MyFile* pf = new Directory ( "/var/log" );

	std::cout << pf->name << std::endl;

	Directory* pff = dynamic_cast<Directory*>(pf);

	if ( typeid(pff) == typeid(Directory*) )
		pff->list();
	else
		std::cout << "Error" << std::endl;

	delete pf;

	return 0;
}
