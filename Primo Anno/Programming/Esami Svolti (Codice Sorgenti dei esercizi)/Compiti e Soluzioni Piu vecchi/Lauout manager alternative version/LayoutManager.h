/*
 * LayoutManager.h
 *
 *  Created on: 08/lug/2015
 *      Author: davidenesi
 */

#ifndef LAYOUTMANAGER_H_
#define LAYOUTMANAGER_H_

#include <list>
#include <iostream>
#include "Widget.h"
#include "Button.h"
#include "TextArea.h"

class LayoutManager: public Widget {
public:
	LayoutManager() {
	}
	;
	virtual ~LayoutManager() {
		for (std::list<Widget*>::iterator itr = elements.begin();
				itr != elements.end(); itr++) {
			delete *itr;
			*itr = 0;
		}
	}

	virtual void draw() {
		for (std::list<Widget*>::const_iterator itr = elements.begin();
				itr != elements.end(); itr++) {
			(*itr)->draw();
		}
	}

	void addWidget(Widget* w) {
		elements.push_back(w);
	}
	void removeWidget(Widget* w) {
		elements.remove(w);
	}

	LayoutManager(const LayoutManager& rlm) {
		for (std::list<Widget*>::const_iterator itr = rlm.elements.begin();
				itr != rlm.elements.end(); itr++) {
			Widget* w = *itr;
			elements.push_back(w);
		}
	}

	LayoutManager& operator=(const LayoutManager& rlm) {
		if (this != &rlm) {
			for (std::list<Widget*>::iterator itr = elements.begin();
					itr != elements.end(); itr++) {
				elements.remove(*itr);
			}
			for (std::list<Widget*>::const_iterator itr = rlm.elements.begin();
					itr != rlm.elements.end(); itr++) {
				Widget* w = *itr;
				elements.push_back(w);
			}
		}
		return *this;
	}

private:
	std::list<Widget*> elements;
};

#endif /* LAYOUTMANAGER_H_ */
