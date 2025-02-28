#include <iostream>
#include "greeter.h" // Questo va a cercare anche nelle cartelle del progetto

void sayHello(std::string name) {
    std::cout << "Hello, " << name << std::endl;
}