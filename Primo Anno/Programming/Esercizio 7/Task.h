#ifndef TASK_H
#define TASK_H

#include <string>
#include "Date.h"

class Task {
public:
    explicit Task(const std::string description="", bool done=false, Date d=Date());

    std::string description;
    bool completed;
    Date deadline;
};


#endif //TASK_H
