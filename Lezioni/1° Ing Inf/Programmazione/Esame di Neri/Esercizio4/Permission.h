//
// Created by neri on 23/07/25.
//

#ifndef PERMISSION_H
#define PERMISSION_H
#include <list>
#include <string>

class Permission {
protected:
    bool onlyReading;
    std::list<std::string> superUsers;
public:
    Permission() : onlyReading(true) {}
    virtual ~Permission() {}

    virtual void addUser(std::string current, std::string newUser) = 0;
    virtual void removeUser(std::string current, std::string removeUser) = 0;
    virtual void setReadingOnly(bool newValue) = 0;

    // Dummy methods
    bool isReading() const { return onlyReading; }
    void getSuperUsers() const {
        std::cout << "Super users on this device" << std::endl;
        for (const auto& user : superUsers) {
            std::cout << user << std::endl;
        }
    }
};

#endif //PERMISSION_H
