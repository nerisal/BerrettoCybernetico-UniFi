//
// Created by neri on 24/07/25.
//

#ifndef ACTIVITY_H
#define ACTIVITY_H
#include <string>


class Activity {
public:
    std::string title;
    std::string description;
    int priority;
    bool is_completed;

    Activity(std::string title, std::string description, int priority, bool completed) : title(title), description(description), priority(priority), is_completed(completed) {}

    std::string getTitle() const { return title; }
    std::string getDescription() const { return description; }
    int getPriority() const { return priority; }
    bool isCompleted() const { return is_completed; }

    void setTitle(const std::string &t) { title = t; }
    void setDescription(const std::string &d) { description = d; }
    void setPriority(const int p) {
       priority = p;
    }
};



#endif //ACTIVITY_H
