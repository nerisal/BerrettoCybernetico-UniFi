//
// Created by neri on 24/07/25.
//

#ifndef ACTIVITYLIST_H
#define ACTIVITYLIST_H
#include <vector>

#include "Activity.h"
#include "ActivityFilter.h"


class ActivityList {
private:
    std::vector<Activity> activities;
    std::vector<ActivityFilter*> filters;
public:
    void addActivity(const Activity& a) {
        activities.push_back(a);
    }

    void addFilter(ActivityFilter* f) {
        filters.push_back(f);
    }

    std::vector<Activity> applyFilters() {
        std::vector<Activity> filtered_activities = activities;
        for (const auto& f : filters) {
            filtered_activities = f->apply(filtered_activities);
        }

        return filtered_activities;
    }
};



#endif //ACTIVITYLIST_H
