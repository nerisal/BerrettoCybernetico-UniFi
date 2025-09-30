//
// Created by neri on 24/07/25.
//

#include "IsCompletedFilter.h"

std::vector<Activity> IsCompletedFilter::apply(std::vector<Activity> activities) {
    std::vector<Activity> result;

    for (const auto &activity : activities) {
        if (activity.isCompleted() == completed) {
            result.push_back(activity);
        }
    }

    return result;
}
