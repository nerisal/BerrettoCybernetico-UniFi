//
// Created by m3ta on 7/19/2018.
//

#ifndef BANC_USERSMARTCARDADAPTER_H
#define BANC_USERSMARTCARDADAPTER_H


#include "UserLogin.h"
#include "SmartCardReader.h"

class UserSmartCardAdapter : public UserLogin {
public:
    explicit UserSmartCardAdapter(SmartCardReader* smartCard):adaptee(smartCard){}
    UserSmartCardAdapter(std::string key){
        adaptee=new SmartCardReader(key);
    }

    virtual bool checkCredentials(std::string username, std::string password)override {
        adaptee->isLoginOK(username, password);
    }

private:
    SmartCardReader* adaptee;
};


#endif //BANC_USERSMARTCARDADAPTER_H
