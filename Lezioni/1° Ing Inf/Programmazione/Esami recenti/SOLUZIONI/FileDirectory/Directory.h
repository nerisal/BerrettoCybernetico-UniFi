/*
 * Directory.h
 *
 *  Created on: 12 gen 2017
 *      Author: silver III
 */

#ifndef DIRECTORY_H_
#define DIRECTORY_H_

#include <vector>
#include "MyFile.h"

class Directory : public MyFile {
public:
	explicit Directory(std::string name) : MyFile(name) {}
	virtual ~Directory() {}
	void list() {
		std::cout << "Directory list" << std::endl;
	}
	std::vector<MyFile*> entries;
};


#endif /* DIRECTORY_H_ */
