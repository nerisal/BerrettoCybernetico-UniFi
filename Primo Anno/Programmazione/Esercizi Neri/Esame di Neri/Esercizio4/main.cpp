#include <iostream>

#include "WindowsFactory.h"
#include "MacOsFactory.h"
#include "LinuxFactory.h"
#include "WindowsFile.h"

//#define WINDOWS
#define LINUX
//#define MACOS

int main () {
#ifdef WINDOWS
    std::unique_ptr<WindowsFactory> factory = std::make_unique<WindowsFactory>();
    std::string defaultUser = "admin";
#elif defined(MACOS)
    std::unique_ptr<MacOsFactory> factory = std::make_unique<MacOsFactory>();
    std::string defaultUser = "mainUser";
#else LINUX
    std::unique_ptr<LinuxFactory> factory = std::make_unique<LinuxFactory>();
    std::string defaultUser = "root";
#endif

    std::unique_ptr<File> file1 = factory->createFile("My File", 10000);
    std::unique_ptr<File> file2 = factory->createFile("My Best File", 19752);
    std::unique_ptr<Directory> dir = factory->createDirectory("My Directory");
    std::unique_ptr<Permission> per = factory->createPermission();

    std::cout << "\nRinomino il file: " << file1->getName() << std::endl;
    file1->rename("A New Name");
    std::cout << file1->getName() << std::endl;

    dir->addFile(std::move(file1));
    dir->addFile(std::move(file2));
    std::cout << std::endl;

    std::cout << "Aggiungo Neri come nuovo User" << std::endl;
    per->setReadingOnly(true);
    per->addUser(defaultUser, "Neri");
    per->getSuperUsers();

    std::cout << "\nStampo tutti i files nella mia directory" << std::endl;
    dir->getFiles();

    std::cout << "\nRinomino la directory" << std::endl;
    dir->rename("New Directory");
    std::cout << "\nStampo tutti i files nella mia directory" << std::endl;
    dir->getFiles();

    return 0;
}