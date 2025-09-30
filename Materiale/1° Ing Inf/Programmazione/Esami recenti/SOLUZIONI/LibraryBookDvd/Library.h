//
// Created by m3tacybmint on 5/22/19.
//

#ifndef LIBRARYBOOKDVD_LIBRARY_H
#define LIBRARYBOOKDVD_LIBRARY_H

#include "headers.h"

class Library {
public:
    Library(){}

    virtual void printInfo(){
        std::cout << "Default print info if not exists one" << std::endl;
    }

    void addToLibrary(Library* newElement){
        _libraryList.push_back(newElement);
    }
    void removeFromList(Library* removeElement){
        _libraryList.remove(removeElement);
    }
    void printList(){
        for(std::list<Library*>::iterator itr = _libraryList.begin(); itr != _libraryList.end(); ++itr)
            (*itr)->printInfo();
    }


private:
    std::list<Library* > _libraryList;
};


#endif //LIBRARYBOOKDVD_LIBRARY_H
