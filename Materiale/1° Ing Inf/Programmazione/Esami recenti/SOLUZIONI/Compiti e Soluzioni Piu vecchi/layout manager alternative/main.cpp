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

	LayoutManager* ilMioLayoutManager1 = new LayoutManager();
	LayoutManager* ilMioLM2 = new LayoutManager();

	ilMioLayoutManager1->addWidget(bottone1);
	//ilMioLayoutManager1.addWidget(textArea1);
	//ilMioLayoutManager1.addWidget(bottone2);


	ilMioLayoutManager1->draw();
	std::cout<<std::endl;

	ilMioLM2->addWidget(bottone2);
	ilMioLM2->draw();
	std::cout<<std::endl;

	ilMioLayoutManager1=ilMioLM2;

	ilMioLayoutManager1->draw();
	std::cout<<std::endl;




}
