//
// Created by neri on 23/07/25.
//

#ifndef CLIENT_H
#define CLIENT_H
#include <string>


class Client {
private:
    std::string name;
    int phone_number;
public:
    Client(std::string name, int phone_number) : name(name), phone_number(phone_number) {}

    std::string getName() const;
};



#endif //CLIENT_H
