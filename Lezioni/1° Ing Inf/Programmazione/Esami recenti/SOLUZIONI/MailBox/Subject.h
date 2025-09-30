//
// Created by m3tamanj on 18/06/18.
//

#ifndef MAILBOX_SUBJECT_H
#define MAILBOX_SUBJECT_H

#include "header.h"
#include "Observer.h"

class Subject {
public:
    virtual void addObserver(Observer* newObserver) = 0;
    virtual void removeObserver(Observer* deletedObserver) = 0;
    virtual void notify() = 0;
protected:
    virtual ~Subject(){}
};


#endif //MAILBOX_SUBJECT_H
