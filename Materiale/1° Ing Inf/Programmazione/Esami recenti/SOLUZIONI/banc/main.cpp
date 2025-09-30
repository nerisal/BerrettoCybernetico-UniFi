#include <iostream>
#include "UserLogin.h"
#include "UserOTPLogin.h"
#include "SmartCardReader.h"
#include "UserSmartCardAdapter.h"

int main() {
    std::cout << "USER LOGIN INTERFACE TEST" << std::endl;
    std::cout << "#########################" << std::endl;
    UserLogin* userLogin = new UserOTPLogin("Test");

    std::string userPassword;
    std::string userPhone = "+39 123 456 7890";
    UserOTPLogin* userOTPLogin = dynamic_cast<UserOTPLogin*>(userLogin);
    if(userOTPLogin)
        userPassword = userOTPLogin->sendOTP(userPhone);
    if(userLogin->checkCredentials("Test", userPassword))
        std::cout << "Logging in." << std::endl;

    std::cout << "\nUSER SMASRT CARD READER TEST" << std::endl;
    std::cout << "#########################" << std::endl;
    SmartCardReader smartCardReader("0xDECAFBAD");

    smartCardReader.setUserName("Lu");
    smartCardReader.setUserPassword("lu123");
    if(smartCardReader.isLoginOK(smartCardReader.encryptString("Lu"), smartCardReader.encryptString("lu123"))){
        std::cout << "Logging in..." << std::endl;
    }


    UserSmartCardAdapter* userSmartCardAdapter = new UserSmartCardAdapter(&smartCardReader);

    std::cout << "\nSIMPLE ADAPTER TEST. (Running isLoginOK inside from checkCredentials) " << std::endl;
    userSmartCardAdapter->checkCredentials("Lu", "lu123");

    return 0;
}