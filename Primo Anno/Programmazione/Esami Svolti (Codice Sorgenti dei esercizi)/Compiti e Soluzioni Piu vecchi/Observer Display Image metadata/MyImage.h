/*
 * MyImage.h
 *
 *  Created on: 05/lug/2015
 *      Author: davidenesi
 */

#ifndef MYIMAGE_H_
#define MYIMAGE_H_
#include <list>

class MyImage :public Subject{
public:
	MyImage():_X(100),_Y(100),_channels(3),_transp(1.0){};
	virtual ~MyImage();
	void setParams(int X,int Y, int channels,float transp){
		if (X<0)
			X=100;
		if (Y<0)
			Y=100;
		if (channels<0)
			channels=3;
		if (transp<0 || transp>1)
			transp(1.0);
	}
	void registerObserver(Observer* o){
		_observers.push_back(o);
	}
	void removeObserver(Observer* o){
		_observers.remove(o);
	}
	void notifyObserver(){
		for (std::list<Observer*>::iterator itr = _observers.begin();itr!=_observers.end();++itr){
			Observer* observer=*itr;
			observer->update(_X,_Y,_channels,_transp);
		}
	}
private:
	int _X,_Y;
	int _channels;
	float _transp;
	std::list<Observer*> _observers;
};

#endif /* MYIMAGE_H_ */
