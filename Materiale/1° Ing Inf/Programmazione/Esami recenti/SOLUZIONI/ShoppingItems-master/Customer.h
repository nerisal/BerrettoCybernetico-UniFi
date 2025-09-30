//
// Created by UserW7m3ra on 7/21/2017.
//

#ifndef BERTINIBUYITEMS_CUSTOMER_H
#define BERTINIBUYITEMS_CUSTOMER_H


#include "header.h"
#include "Order.h"
#define yes 1
#define no 0

class Customer : public Order{
public:
    Customer(string name = "", string surname = "", string address = "", string email = "", double balanceAcount  = 0.00, bool premiumUser = false, string username = "", string password =" ")
            : name(name), surname(surname), address(address), email(email), balanceAcount(balanceAcount), premiumUser(premiumUser), username(username), password(password) {}

    Customer createAccount(Customer &cus){
        again:
        cout << "CREATE ACCOUNT" << endl;
        cout << "--------------" << endl;
        string newUsername, newPassword, verPass;
        cout << "Insert username: "; cin >> newUsername; cus.setUsername(newUsername);
        cout << "Insert password: "; cin >> newPassword; cus.setPassword(newPassword);
        cout << "Verify password: "; cin >> verPass;
        if(newPassword == verPass){
            cout << "\nAccount created successfully!\n" << endl;
            pauseClear();
            return cus;
        }else{
            cout << "\n\nPasswords does not match. Please try again.\n" << endl;
            pauseClear();
            goto again;
        }
    }
    bool login(){
        Customer cus;
        string newUsername = "", newPassword = "";
        again:
        cout << "LOGIN TO YOUR ACCOUNT" << endl;
        cout << "---------------------" << endl;
        cout << "Insert username: "; cin >> newUsername; cus.setUsername(newUsername);
        cout << "Insert password: "; cin >> newPassword; cus.setPassword(newPassword);
        string cusUsername = cus.getUsername();
        string cusPassword = cus.getPassword();
        if(username == cusUsername && password == cusPassword){
            cout << "\nLogin successfully!\n" << endl;
        }
        else{
            cout << "\nIncorrect username or password. Try again!\n" << endl;
            system("pause"); system("cls");
            goto again;
        }
        pauseClear();
        return true;
    }
    Customer changeSettings(Customer &cus){
            string anws, newName, newSurname, newAddress, newEmail, newPassword;
            double newBalanceAccount;
            bool premiumUser = false;
            again:
            cout << "\nChange personal info (yes, no): "; cin >> anws;
            if(anws == "yes" || anws == "y"){
                    int slc;
                    cout << "\nSelect ID number: "; cin >> slc;
                    switch (slc){
                            case 1: cout << "New name: "; cin >> newName; cus.setName(newName); break;
                            case 2: cout << "New surname: "; cin >> newSurname; cus.setSurname(newSurname); break;
                            case 3: cout << "New address: "; cin >> newAddress; cus.setAddress(newAddress); break;
                            case 4: cout << "New email: "; cin >> newEmail; cus.setEmail(newEmail); break;
                            case 5: cout << "New balance account: "; cin >> newBalanceAccount; cus.setBalanceAcount(newBalanceAccount); break;
                            case 6: cout << "New password: "; cin >>  newPassword; cus.setPassword(newPassword); break;
                            default: display(); break;
                    }
                    cout << "\nAccount settings updated successfully!\n" << endl;
                    pauseClear();
                    display();
                    goto again;
            }
            else {
                    cout << endl;
                    pauseClear();
            }
        return cus;
    }
    void pauseClear(){
                system("pause");system("clear"); system("cls");
    }
    void display(){
        cout << "\nPERSONAL ACCOUNT INFO" << endl;
        cout << "---------------------" << endl;
        cout << "[0] Username: " << username << "\n[1] Name: "  << name << "\n[2] Surname: " << surname << "\n[3] Address: " << address << "\n[4] Email: " << email << endl;
        cout << "[5] Balance account: " << setprecision(2) << fixed << balanceAcount << "$" << "\n[6] Password: " << password <<"\n[7] Premium: " << premiumUser << endl << endl;

          //  pauseClear();
    }

    const string &getName() const {return name;}
    void setName(const string &newName){this->name = newName;}
    const string &getSurname() const{return surname;}
    void setSurname(const string &newSurname){this->surname = newSurname;}
    const string &getAddress() const{return address;}
    void setAddress(const string &newAddress){this->address = newAddress;}
    const string &getEmail() const{return email;}
    void setEmail(const string &newEmail) { this->email = newEmail; }
    bool isPremiumUser() const{return premiumUser;}
    void setPremiumUser(bool newPremiumUser){this->premiumUser = newPremiumUser;}
    double getBalanceAcount() const { return balanceAcount; }
    void setBalanceAcount(double newBalanceAcount) { this->balanceAcount = newBalanceAcount; }
    const string &getUsername() const {return username;}
    void setUsername(const string &newUsername){this->username = newUsername;}
    const string &getPassword() const {return password;}
    void setPassword(const string &newPassword) {this->password = newPassword;}

private:
    string name, surname, address, email, username, password;
    bool premiumUser;
    double balanceAcount;
    vector <Items> itemsList;
};


#endif //BERTINIBUYITEMS_CUSTOMER_H
