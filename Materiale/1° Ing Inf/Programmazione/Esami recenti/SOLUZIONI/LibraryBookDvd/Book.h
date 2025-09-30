//
// Created by m3tacybmint on 5/22/19.
//

#ifndef LIBRARYBOOKDVD_BOOK_H
#define LIBRARYBOOKDVD_BOOK_H

#include "headers.h"
#include "Library.h"

class Book : public Library {
public:
    Book(std::string bookTitle = "", std::string bookActor = "", std::string bookEditor = "", int bookNumOfPages = 0) {
        this->_bookTitle = bookTitle;
        this->_bookActor = bookActor;
        this->_bookEditor = bookEditor;
        this->_bookNumOfPages = bookNumOfPages;
    }
    Book() = default;

    void printInfo() override{
        std::cout << "Book's title: " << _bookTitle << std::endl;
        std::cout << "Book's Actor: " << _bookActor << std::endl;
        std::cout << "Book's editor: " << _bookEditor << std::endl;
        std::cout << "Book's number of pages: " << _bookNumOfPages << std::endl;
        std::cout << std::endl;
    }

    void setBookTitle(const std::string &bookTitle) {_bookTitle = bookTitle;}
    void setBookActor(const std::string &bookActor) {_bookActor = bookActor;}
    void setBookEditor(const std::string &bookEditor) {_bookEditor = bookEditor;}
    void setBookNumOfPages(int bookNumOfPages) {_bookNumOfPages = bookNumOfPages;}

    const std::string &getBookTitle() const {return _bookTitle;}
    const std::string &getBookActor() const {return _bookActor;}
    const std::string &getBookEditor() const {return _bookEditor;}
    int getBookNumOfPages() const {return _bookNumOfPages;}

private:
    std::string _bookTitle;
    std::string _bookActor;
    std::string _bookEditor;
    int _bookNumOfPages;
};


#endif //LIBRARYBOOKDVD_BOOK_H
