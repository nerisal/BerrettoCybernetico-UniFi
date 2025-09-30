#include "header.h"
#include "Subject.h"
#include "Observer.h"
#include "GuiNotifier.h"
#include "IconBadgeMonitor.h"
#include "MailBox.h"

int main() {
    MailBox mailBox;
    GuiNotifier guiNotifier(&mailBox,false);
    IconBadgeMonitor iconBadgeMonitor(&mailBox);

    Mail firstMail("First", "Email 1", "Text first email", false);
    Mail secondMail("Second" ,"Email 2", "Text second email", false );
    Mail thirdMail("Third", "Email 3", "Text third email", false);
    Mail fourthMail("Fourth", "Email 4", "Text fourth email", false);

    mailBox.addMail(firstMail);
    mailBox.addMail(secondMail);
    mailBox.addMail(thirdMail);
    mailBox.addMail(fourthMail);

    mailBox.printEmails();


    mailBox.readEmail(1);

    mailBox.printEmails();





    return 0;
}