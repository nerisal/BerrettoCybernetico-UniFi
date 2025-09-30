//
// Created by m3tamanj on 18/06/18.
//

#ifndef MAILBOX_MAIL_H
#define MAILBOX_MAIL_H

#include "header.h"

class Mail {
public:

    Mail(const string &_title, const string &_sender, const string &_tetx, bool _read) : _title(_title),
                                                                                         _sender(_sender), _tetx(_tetx),
                                                                                         _read(_read) {}

    void display(){
        cout << "[EMAIL TITLE:] " << _title << " [EMAIL SENDER]: " << _sender << " [EMAIL TEXT]: " << _title << " [READ 0/1]: " << _read << endl;
     }
    /*Getters/Setters*/
    const string &get_title() const { return _title; }
    void set_title(const string &_title) { Mail::_title = _title; }
    const string &get_sender() const { return _sender; }
    void set_sender(const string &_sender) { Mail::_sender = _sender; }
    const string &get_tetx() const { return _tetx; }
    void set_tetx(const string &_tetx) { Mail::_tetx = _tetx; }
    bool is_read() const { return _read; }
    void set_read(bool _read) { Mail::_read = _read; }

private:
    string _title, _sender, _tetx;
    bool _read;
};


#endif //MAILBOX_MAIL_H
