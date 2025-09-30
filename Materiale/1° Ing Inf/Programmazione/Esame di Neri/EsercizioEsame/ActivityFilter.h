//
// Created by neri on 24/07/25.
//

#ifndef ACTIVITYFILTER_H
#define ACTIVITYFILTER_H
#include <vector>

#include "Activity.h"

class ActivityFilter {
public:
    virtual ~ActivityFilter() = default;
    virtual std::vector<Activity> apply(std::vector<Activity> activities) = 0;
};



#endif //ACTIVITYFILTER_H
