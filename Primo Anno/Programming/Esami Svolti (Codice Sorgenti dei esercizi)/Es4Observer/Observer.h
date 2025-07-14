//
// Created by Monica Eron on 08/01/18.
//

#ifndef ES4_OBSERVER_OBSERVER_H
#define ES4_OBSERVER_OBSERVER_H

class Observer {
public:
    virtual ~Observer() {}
    virtual void update() = 0;
};

#endif //ES4_OBSERVER_OBSERVER_H
