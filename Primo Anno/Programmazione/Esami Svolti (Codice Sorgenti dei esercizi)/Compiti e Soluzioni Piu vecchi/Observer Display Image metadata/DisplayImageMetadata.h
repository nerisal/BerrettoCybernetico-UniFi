/*
 * DisplayImageMetadata.h
 *
 *  Created on: 05/lug/2015
 *      Author: davidenesi
 */

#ifndef DISPLAYIMAGEMETADATA_H_
#define DISPLAYIMAGEMETADATA_H_
#include <iostream>
using namespace std;
class DisplayImageMetadata: public Observer, public DisplayImage {
public:
	DisplayImageMetadata();
	virtual ~DisplayImageMetadata(){
		imageData->removeObserver(this);
	}
	virtual void upadte(int X,int Y, int channels,float transp){
		_X=X;
		_Y=Y;
		_channels=channels;
		_transp=transp;
		display();
	}

	virtual void display() const {
		cout<<"Image metadata"<<endl;
		cout<<"X:"<< _X<<endl;
		cout<<"Y:"<< _Y<<endl;
		cout<<"channels:"<< _channels<<endl;
		cout<<"transp:"<< _transp<<endl;
	}

private:
	Subject* imageData;
	int _X, _Y;
	int _channels;
	float _transp;
};

#endif /* DISPLAYIMAGEMETADATA_H_ */
