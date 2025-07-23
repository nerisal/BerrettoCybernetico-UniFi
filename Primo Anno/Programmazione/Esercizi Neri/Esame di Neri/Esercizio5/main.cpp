#include <iostream>
#include <vector>

#include "ReservationSystem.h"

int main() {
    // Setup
    auto system = ReservationSystem();

    system.addTable(1, 4);
    system.addTable(2, 2);
    system.addTable(3, 6);
    system.addTable(4, 9);

    //  Registered Guests:
    std::vector<std::shared_ptr<Client>> myClients;
    myClients.emplace_back(std::make_shared<Client>("Pallino", 3331117778));
    myClients.emplace_back(std::make_shared<Client>("Pierino", 3456759800));
    myClients.emplace_back(std::make_shared<Client>("Tito", 1234567789));
    myClients.emplace_back(std::make_shared<Client>("Esmeralda", 9088123467));

    // Dummy reservations
    system.makeReservation(2, myClients[0]);
    system.makeReservation(7, myClients[2]);
    system.makeReservation(2, myClients[3]);

    system.printReservations();

    // Erasing a reservation for Esmeralda
    std::cout << "\nEsmeralda ha deciso di cancellare la prenotazione" << std::endl;
    system.removeReservation(myClients[3]->getName());
    system.printReservations();

    std::cout << "\nOra Pallino vuole prenotare per 4 persone" << std::endl;
    system.makeReservation(4, myClients[1]);
    system.printReservations();
}
