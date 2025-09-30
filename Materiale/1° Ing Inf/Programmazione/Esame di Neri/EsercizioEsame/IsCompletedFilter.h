//
// Created by neri on 24/07/25.
//

#ifndef ISCOMPLETEDFILTER_H
#define ISCOMPLETEDFILTER_H
#include "ActivityFilter.h"


class IsCompletedFilter : public ActivityFilter{
public:
    explicit IsCompletedFilter(const bool c) : completed(c){}
    virtual std::vector<Activity> apply(std::vector<Activity> activities) override;
private:
    bool completed;
};

#endif //ISCOMPLETEDFILTER_H
