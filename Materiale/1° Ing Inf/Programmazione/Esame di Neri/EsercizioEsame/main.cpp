#include <iostream>

#include "ActivityList.h"
#include "HasPriorityFilter.h"
#include "IsCompletedFilter.h"

int main() {
    auto activities = ActivityList();

    auto activity1 = Activity("Spolverare", "Pulire la camera", 1, false);
    auto activity2 = Activity("Universita", "Prepararsi per gli esami", 5, true);
    auto activity3 = Activity("Palestra", "Andare in palestra", 3, true);
    auto activity4 = Activity("Leggere", "Leggere un libro", 3, true);
    // Aggiungo delle dummy activities
    activities.addActivity(activity1);
    activities.addActivity(activity2);
    activities.addActivity(activity3);
    activities.addActivity(activity4);

    auto filter1 = IsCompletedFilter(true);
    auto filter2 = HasPriorityFilter(3);

    activities.addFilter(&filter1);
    activities.addFilter(&filter2);

    std::vector<Activity> filtered_activities = activities.applyFilters();
    for (auto& activity : filtered_activities) {
        std::cout << "Attività: " <<  activity.getTitle() << " Descrizione: " << activity.getDescription() << " Priority: " << activity.getPriority() << " Satus: " << activity.isCompleted()<< std::endl;
    }


    return 0;
}
