#ifndef ABSTRACTFACTORY_H
#define ABSTRACTFACTORY_H
#include "Button.h"
#include "Panel.h"

class AbstractFactory{
	public: 
		virtual Button* createButton() = 0;
		virtual Panel* createPanel() = 0;
};

#endif
