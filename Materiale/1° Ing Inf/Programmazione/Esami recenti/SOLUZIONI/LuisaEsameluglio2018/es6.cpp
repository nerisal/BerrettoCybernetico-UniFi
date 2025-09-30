#include <iostream>
#include <chrono>

class UserLogin{
public:
    UserLogin(){}
    explicit UserLogin(std::string& user):userName(user){}
    virtual ~UserLogin(){}

    virtual bool checkCredentials(std::string username, std::string password)=0;

protected:
    std::string userName;
    std::string userPassword;
};


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

class UserSmartCardAdapter:public UserLogin, private SmartCardReader{
public:
    explicit UserSmartCardAdapter(SmartCardReader& adaptee):SmartCardReader(adaptee.getSecretKey()){}
    virtual ~UserSmartCardAdapter(){}

    virtual bool checkCredentials(std::string username, std::string password)override {
        SmartCardReader::isLoginOK(username, password);
    }
};

//class UserSmartCardAdapter:public UserLogin{
//public:
//    explicit UserSmartCardAdapter(SmartCardReader* smartCard):adaptee(smartCard){}
//    UserSmartCardAdapter(std::string key){
//        adaptee=new SmartCardReader(key);
//    }
//
//    virtual bool checkCredentials(std::string username, std::string password)override {
//        adaptee->isLoginOK(username, password);
//    }
//
//private:
//    SmartCardReader* adaptee;
//};


int main() {
    std::cout << "USER LOGIN INTERFACE TEST" << std::endl;
    UserLogin *userLogin = new UserOTPLogin("Test");

    std::string userPassword;
    std::string userPhone = "+39 123 456 7890";
    UserOTPLogin *userOTPLogin = dynamic_cast<UserOTPLogin *>(userLogin);
    if (userOTPLogin)
        userPassword = userOTPLogin->sendOTP(userPhone);
    if (userLogin->checkCredentials("Test", userPassword))
        std::cout << "Logging in." << std::endl;

    std::cout << "\nUSER SMART CARD READER TEST" << std::endl;
    SmartCardReader smartCardReader("0xDECAFBAD");

    smartCardReader.setUserName("Luisa");
    smartCardReader.setUserPassword("lu123");
    if (smartCardReader.isLoginOK(smartCardReader.encryptString("Luisa"), smartCardReader.encryptString("lu123"))) {
        std::cout << "Logging in..." << std::endl;
    }


    //UserSmartCardAdapter *userSmartCardAdapter = new UserSmartCardAdapter(&smartCardReader);
    UserSmartCardAdapter *userSmartCardAdapter = new UserSmartCardAdapter(smartCardReader);

    std::cout << "\nSIMPLE ADAPTER TEST. (Running isLoginOK inside from checkCredentials) " << std::endl;
    userSmartCardAdapter->checkCredentials("Lu", "lu123");
}