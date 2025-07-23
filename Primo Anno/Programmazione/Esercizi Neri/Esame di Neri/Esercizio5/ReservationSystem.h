//
// Created by neri on 23/07/25.
//

#ifndef RESERVATIONSYSTEM_H
#define RESERVATIONSYSTEM_H
#include <list>
#include <map>
#include <memory>

#include "Reservation.h"

class ReservationSystem {
private:
    std::map<std::string, Reservation> reservations;
    std::list<std::shared_ptr<Table>> tables;
public:
    ReservationSystem() = default;
    void addTable(int number, int capacity);

    std::list<std::shared_ptr<Table>> getFreeTables(int guests);
    void makeReservation(int guests, std::shared_ptr<Client> client);
    void removeReservation(std::string name);
    void printReservations();
};

#endif //RESERVATIONSYSTEM_H
