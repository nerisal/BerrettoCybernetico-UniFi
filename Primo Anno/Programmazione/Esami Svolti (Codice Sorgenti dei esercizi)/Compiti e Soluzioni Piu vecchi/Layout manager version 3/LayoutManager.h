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
	LayoutManager(){};
	virtual ~LayoutManager(){};

	virtual void draw(){
			for (std::list<Widget*>::const_iterator itr = elements.begin();
					itr!=elements.end();itr++){
				(*itr)->draw();
			}
		}

	void addWidget(Widget* w){
		elements.push_back(w);
	}
	void removeWidget(Widget* w){
		elements.remove(w);
	}

private:
	std::list<Widget*> elements;
};

#endif /* LAYOUTMANAGER_H_ */
