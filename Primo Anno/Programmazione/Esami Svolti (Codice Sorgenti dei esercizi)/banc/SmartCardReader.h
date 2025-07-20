//
// Created by m3ta on 7/19/2018.
//

#ifndef BANC_SMARTCARDREADER_H
#define BANC_SMARTCARDREADER_H


#include <string>

class SmartCardReader {
public:
    SmartCardReader(std::string key) : secretKey(key), userPassword(""), userName("") {}

    bool isLoginOK(std::string encryptedUser, std::string encryptedPassword) const {
        if ((userPassword != "") && (userName != "")) {
            if ((encryptedUser == userName) && (encryptedPassword == userPassword)) {
                std::cout << "Test OK" << std::endl;
                return true;
            }
            else return false;
        } else
            return false;
    }

    void setUserName(std::string user) {
        userName = encryptString(user);
    }

    void setUserPassword(const std::string &password) {
        this->userPassword = encryptString(password);
    }

    std::string getSecretKey(){
        return secretKey;
    }

    std::string encryptString(std::string value) {
        std::cout<<"encrypted_" +secretKey + "_" + value<<std::endl;
        return "encrypted_" +secretKey + "_" + value;
    }


private:
    std::string secretKey;
    std::string userPassword;
    std::string userName;
};


#endif //BANC_SMARTCARDREADER_H
