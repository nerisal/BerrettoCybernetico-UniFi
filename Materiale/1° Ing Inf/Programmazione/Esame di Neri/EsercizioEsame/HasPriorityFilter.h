//
// Created by neri on 24/07/25.
//

#ifndef HASPRIORITYFILTER_H
#define HASPRIORITYFILTER_H
#include "ActivityFilter.h"


class HasPriorityFilter : public ActivityFilter{
public:
    explicit HasPriorityFilter(const int p) : priority(p){}
    virtual std::vector<Activity> apply(std::vector<Activity> activities) override;
private:
    int priority;
};



#endif //HASPRIORITYFILTER_H
