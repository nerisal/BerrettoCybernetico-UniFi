/*
 * DisplayImageContent.h
 *
 *  Created on: 05/lug/2015
 *      Author: davidenesi
 */

#ifndef DISPLAYIMAGECONTENT_H_
#define DISPLAYIMAGECONTENT_H_
#include <iostream>

class DisplayImageContent: public Observer, public DisplayImage {
public:
	DisplayImageContent();
	virtual ~DisplayImageContent();
	virtual void upadte(int X,int Y, int channels,float transp){
		display();
	};
	virtual void display(){
		std::cout<<"DisplayImageContent"<<std::endl;
	}
};

#endif /* DISPLAYIMAGECONTENT_H_ */
