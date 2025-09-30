/*
 * main.cpp
 *
 *  Created on: 08/lug/2015
 *      Author: davidenesi
 */

#include <iostream>
#include "Widget.h"
#include "Button.h"
#include "TextArea.h"
#include "LayoutManager.h"


int main (){
	Widget* bottone1= new Button("primo bottone");
	Widget* bottone2= new Button("secondo bottone");
	Widget* textArea1= new TextArea("prima text area");
	Widget* bottone3= new Button("terzo bottone");

	LayoutManager ilMioLayoutManager;

	ilMioLayoutManager.addWidget(bottone1);
	ilMioLayoutManager.addWidget(bottone3);
	ilMioLayoutManager.addWidget(textArea1);
	ilMioLayoutManager.addWidget(bottone2);


	ilMioLayoutManager.draw();

}
