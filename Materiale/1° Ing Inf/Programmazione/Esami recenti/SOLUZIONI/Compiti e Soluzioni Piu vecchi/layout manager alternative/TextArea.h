/*
 * TextArea.h
 *
 *  Created on: 08/lug/2015
 *      Author: davidenesi
 */

#ifndef TEXTAREA_H_
#define TEXTAREA_H_

#include <iostream>
#include "Widget.h"

class TextArea: public Widget {
public:
	TextArea(std::string t) :
			text(t) {
	}
	virtual ~TextArea() {
	}
	virtual void draw() {
		std::cout << "Disegno un'area di testo... " << text << std::endl;
	}
	TextArea(const TextArea& rta){
			text=rta.text;
		}
	TextArea& operator=(const TextArea& rta){
			if(this!=&rta)
				text=rta.text;
			return *this;
		}
private:
	std::string text;
};

#endif /* TEXTAREA_H_ */
