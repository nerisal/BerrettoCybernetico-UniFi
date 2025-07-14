//
// Created by m3tamanj on 18/06/18.
//

#ifndef MAILBOX_ICONBADGEMONITOR_H
#define MAILBOX_ICONBADGEMONITOR_H

#include "Observer.h"

class IconBadgeMonitor : public Observer {
public:
    IconBadgeMonitor(MailBox* mailBox) : mailBox(mailBox){
        mailBox->addObserver(this);
    }
    ~IconBadgeMonitor(){
        mailBox->removeObserver(this);
    }
    virtual void update() override {
        //
    }
    virtual void draw() override {
        mailBox->getNumUnreadEmails();
        cout << endl;
    }
private:
    MailBox* mailBox;
};


#endif //MAILBOX_ICONBADGEMONITOR_H
