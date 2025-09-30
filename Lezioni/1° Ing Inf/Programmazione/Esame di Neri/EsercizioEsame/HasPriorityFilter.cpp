//
// Created by neri on 24/07/25.
//

#include "HasPriorityFilter.h"

std::vector<Activity> HasPriorityFilter::apply(std::vector<Activity> activities) {
    std::vector<Activity> result;

    for (const Activity a : activities) {
        if (a.priority == priority) {
            result.push_back(a);
        }
    }

    return result;
}
