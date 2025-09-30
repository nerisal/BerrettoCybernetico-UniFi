/*
 * MyFile.h
 *
 *  Created on: 12 gen 2017
 *      Author: silver III
 */

#ifndef MYFILE_H_
#define MYFILE_H_

#include <iostream>
#include <string.h>

class MyFile {
public:
	explicit MyFile(std::string n) : name (n) {}
	virtual ~MyFile() {}
	virtual void open() {}

	std::string name;
};


#endif /* MYFILE_H_ */
