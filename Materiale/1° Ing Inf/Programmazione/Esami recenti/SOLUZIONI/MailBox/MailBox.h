//
// Created by m3tamanj on 18/06/18.
//

#ifndef MAILBOX_MAILBOX_H
#define MAILBOX_MAILBOX_H

#include "Subject.h"
#include "Mail.h"

class MailBox : public Subject{
public:

    virtual void addObserver(Observer* newObserver) override {
        _observers.push_back(newObserver);
    }
    virtual void removeObserver(Observer* delObserver) override {
        _observers.remove(delObserver);
    }
    virtual void notify() override {
        for(list<Observer*>::iterator itr = _observers.begin(); itr != _observers.end(); ++itr) {
            (*itr)->update();
            (*itr)->draw();
        }
    }

    void addMail(const Mail& newMail){ _emails.push_back(newMail); notify(); }
    void printEmails(){
        int i=0;
        cout << "\n\t\t\t List of available emails" << endl;
        cout << "\t\t\t-------------------------" << endl;
        for(auto itr : _emails){
            cout << "[" << i << "] ";
            itr.display();
            i++;
        }
    }

    const Mail& lastEmail() const{ return _emails.back();}
    void readEmail(int i){
        if(i>=0 && i<_emails.size()){
            cout << "\nREADING EMAIL [" << i << "]" << endl;
            cout << "[TITLE]: " << _emails[i].get_title();
            cout << " [SENDER]: " << _emails[i].get_sender();
            cout << " [TEXT]: " <<_emails[i].get_tetx() << endl;
            _emails[i].set_read(true);
        }
    }
    int getNumUnreadEmails() const{
        int counter=0;
        for(auto itr : _emails){
            if(!itr.is_read())
                ++counter;
        }
        cout << "\nYou have " << counter << " unread emails." << endl;
        return counter;
    }
private:
    string _emailSender, _emailText, _emailTitle;
    vector<Mail> _emails;
    list<Observer*> _observers;

};


#endif //MAILBOX_MAILBOX_H
