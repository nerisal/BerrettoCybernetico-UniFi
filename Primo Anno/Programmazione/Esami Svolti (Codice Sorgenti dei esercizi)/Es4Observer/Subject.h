//
// Created by Monica Eron on 09/01/18.
//

#ifndef ES4_OBSERVER_SUBJECT_H
#define ES4_OBSERVER_SUBJECT_H

#include "Observer.h"
class Subject{
public:
    virtual ~Subject(){}
    virtual void notify() = 0;
    virtual void subscribe(Observer* o) = 0;
    virtual void unsubscribe(Observer* o) = 0;
private:

};

#endif //ES4_OBSERVER_SUBJECT_H
