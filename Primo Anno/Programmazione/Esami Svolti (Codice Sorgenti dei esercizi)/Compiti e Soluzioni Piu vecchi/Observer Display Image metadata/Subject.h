/*
 * Subject.h
 *
 *  Created on: 05/lug/2015
 *      Author: davidenesi
 */

#ifndef SUBJECT_H_
#define SUBJECT_H_

class Subject {
public:
	virtual void registerObserver(Observer* o)=0;
	virtual void removeObserver(Observer* o)=0;
	virtual void notifyObserver(Observer* o)const =0;
protected:
	virtual ~Subject();
};

#endif /* SUBJECT_H_ */
