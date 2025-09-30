//
// Created by m3tamanj on 18/06/18.
//

#ifndef MAILBOX_OBSERVER_H
#define MAILBOX_OBSERVER_H


class Observer {
public:
    virtual void update() = 0;
    virtual void draw() = 0;
protected:
    virtual ~Observer(){}
};


#endif //MAILBOX_OBSERVER_H
