//
// Created by m3ta on 7/19/2018.
//

#ifndef BANC_USEROTPLOGIN_H
#define BANC_USEROTPLOGIN_H

#include <chrono>
#include <iostream>
#include "UserLogin.h"

class UserOTPLogin : public UserLogin {
public:
    explicit UserOTPLogin(std::string user) : UserLogin(user) {}
    std::string sendOTP(std::string telephoneNumber){
        start = std::chrono::system_clock::now();
        std::string password = generateRandomPassword();
        std::cout << "Sending password: " << password << " to telephoneNumber " << telephoneNumber << std::endl;
        return password;
    }

    virtual bool checkCredentials(std::string userName, std::string password) override {
        end = std::chrono::system_clock::now();
        std::chrono::duration<double> diff = end-start;
        if(diff.count() > _maxSec){
            std::cerr <<"OTP token expired. Please retry." << std::endl;
            return false;
        }
        if((this->userName == userName) && (this->userPassword == password))
            return true;
        else{
            std::cerr << "Wrong username or password." << std::endl;
            return false;
        }
    }

private:
    const int _maxSec = 20;
    std::chrono::time_point<std::chrono::system_clock> start;
    std::chrono::time_point<std::chrono::system_clock> end;
    std::string _otpPassword;

    std::string generateRandomPassword(){
        userPassword = std::string("password");
        return userName;
    }
};


#endif //BANC_USEROTPLOGIN_H
