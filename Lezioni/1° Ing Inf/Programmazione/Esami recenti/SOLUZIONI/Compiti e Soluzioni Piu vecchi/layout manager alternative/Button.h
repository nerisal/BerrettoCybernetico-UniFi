/*
 * Button.h
 *
 *  Created on: 08/lug/2015
 *      Author: davidenesi
 */

#ifndef BUTTON_H_
#define BUTTON_H_

#include <iostream>
#include "Widget.h"

class Button: public Widget {
public:
	Button(std::string t) :
			text(t) {
	}
	virtual ~Button() {
	}
	virtual void draw() {
		std::cout << "disegno un bottone.." << text << std::endl;
	}
	Button(const Button& rb){
		text=rb.text;
	}
	Button& operator=(const Button& rb){
		if(this!=&rb)
			text=rb.text;
		return *this;
	}
private:
	std::string text;
};

#endif /* BUTTON_H_ */
