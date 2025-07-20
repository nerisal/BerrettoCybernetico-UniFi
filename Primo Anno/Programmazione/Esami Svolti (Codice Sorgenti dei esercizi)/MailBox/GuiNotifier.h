//
// Created by m3tamanj on 18/06/18.
//

#ifndef MAILBOX_GUINOTIFIER_H
#define MAILBOX_GUINOTIFIER_H

#include "Observer.h"
#include "Mail.h"
#include "MailBox.h"

class GuiNotifier : public Observer{
public:
    GuiNotifier(MailBox *mailBox, bool act) : mailBox(mailBox), _active(act) {
        mailBox->addObserver(this);
    }
    ~GuiNotifier(){
        mailBox->removeObserver(this);
    }

    virtual void update() override {
        string lastSender = mailBox->lastEmail().get_sender();
        string lastTitle = mailBox->lastEmail().get_title();
        string lastText = mailBox->lastEmail().get_tetx();
        cout << "New email arrived!";
        cout << "[EMAIL TITLE] " << lastTitle << " [EMAIL SENDER]: " << lastSender << " [EMAIL TEXT]: " << lastText;

    }
    virtual void draw() override {
       // mailBox->getNumUnreadEmails();
       // cout << endl;
    }

private:
    MailBox* mailBox;
    bool _active;
};


#endif //MAILBOX_GUINOTIFIER_H
