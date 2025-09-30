//
// Created by m3tacybmint on 5/22/19.
//

#ifndef LIBRARYBOOKDVD_DVD_H
#define LIBRARYBOOKDVD_DVD_H

#include "headers.h"
#include "Library.h"

class Dvd : public Library {
public:
    Dvd(std::string dvdTitle = "", std::string dvdRegister = "", int minuteDuration = 0){
        this->_dvdTitle = dvdTitle;
        this->_dvdRegister = dvdRegister;
        this->_minuteFuration = minuteDuration;
    }
    Dvd() = default;

    virtual void printInfo() override {
        std::cout << "Dvd title: " << _dvdTitle << std::endl;
        std::cout << "Dvd's register: " << _dvdRegister << std::endl;
        std::cout << "Dvd's duration time (minutes): " << _minuteFuration << std::endl;
        std::cout << std::endl;
    }


    void setDvdTitle(const std::string &dvdTitle) {_dvdTitle = dvdTitle;}
    void setMinuteFuration(int minuteFuration) {_minuteFuration = minuteFuration;}
    void setDvdRegister(const std::string &dvdRegister) {_dvdRegister = dvdRegister;}

    const std::string &getDvdTitle() const {return _dvdTitle;}
    const std::string &getDvdRegister() const {return _dvdRegister;}
    int getMinuteFuration() const {return _minuteFuration;}



private:
    std::string _dvdTitle;
    std::string _dvdRegister;
    int _minuteFuration;
};


#endif //LIBRARYBOOKDVD_DVD_H
