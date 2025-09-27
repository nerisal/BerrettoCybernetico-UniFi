//
// Created by neri on 23/07/25.
//

#include "ReservationSystem.h"

#include <iostream>

void ReservationSystem::addTable(int number, int capacity) {
    tables.push_back(std::make_shared<Table>(number, capacity));
}

std::list<std::shared_ptr<Table>> ReservationSystem::getFreeTables(int guests) {
    std::list<std::shared_ptr<Table>> freeTables;

    for (auto t : tables) {
        if (t->isFree() && t->getCapacity() == guests) {
            freeTables.push_back(t);
        }
        else if (t -> isFree() && t->getCapacity() > guests) {
            freeTables.push_back(t);
        }
    }

    return freeTables;
}

void ReservationSystem::makeReservation(int guests, std::shared_ptr<Client> client) {
    auto it = getFreeTables(guests).begin();
    (*it)->setIsFree(false);
    reservations.emplace(client->getName(), Reservation(client, *it, guests));
}

void ReservationSystem::removeReservation(std::string name) {
    if (reservations.find(name) != reservations.end()) {
        reservations[name].getTable()->setIsFree(false);
        reservations.erase(name);
    }
}

void ReservationSystem::printReservations() {
    std::cout << "Tonight's reservations:" << std::endl;
    for (auto& t : reservations) {
        std::cout << "Reservation for: " << t.first << " for " << t.second.getGuests()  << " peoples at table number: " << t.second.getTable()->getNumber() << std::endl;
    }
}
