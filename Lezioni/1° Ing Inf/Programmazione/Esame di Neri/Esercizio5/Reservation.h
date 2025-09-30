//
// Created by neri on 23/07/25.
//

#ifndef RESERVATION_H
#define RESERVATION_H
#include <memory>

#include "Client.h"
#include "Table.h"


class Reservation {
private:
    std::shared_ptr<Client> client;
    std::shared_ptr<Table> table;
    int guests;
    std::string name;
public:
    Reservation(std::shared_ptr<Client> c, std::shared_ptr<Table> t, int g) : client(c), table(t), guests(g), name(c->getName()) {}
    Reservation() {};

    std::string getName() { return name; }
    int getGuests() { return guests; }
    std::shared_ptr<Client> getClient() { return client; }
    std::shared_ptr<Table> getTable() { return table; }
};



#endif //RESERVATION_H
