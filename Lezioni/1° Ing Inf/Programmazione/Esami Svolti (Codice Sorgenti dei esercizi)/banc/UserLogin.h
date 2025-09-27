//
// Created by m3ta on 7/19/2018.
//

#ifndef BANC_USERLOGIN_H
#define BANC_USERLOGIN_H

#include <string>

class UserLogin {
public:
    UserLogin(){}
    explicit UserLogin(std::string& user):userName(user){}
    virtual ~UserLogin(){}

    virtual bool checkCredentials(std::string username, std::string password)=0;

protected:
    std::string userName;
    std::string userPassword;
};


#endif //BANC_USERLOGIN_H
