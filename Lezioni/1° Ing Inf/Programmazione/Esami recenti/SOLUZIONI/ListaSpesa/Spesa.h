//
// Created by salvatore on 04/07/18.
//

#ifndef LISTASPESA_SPESA_H
#define LISTASPESA_SPESA_H


#include <string>
#include <iostream>
#include <algorithm>
#include <map>
#include <iterator>


struct Articolo{

    std::string name;
    int qty;

    void display(){
        std::cout << "Articolo: " << name << " || Quantità: " << qty << std::endl;
    }

};

class Spesa {
private:
    Articolo articolo;
    std::multimap <int,Articolo> listaArt;
public:
    void printAll(){
      for(auto itr:listaArt){
          std::cout << "Articolo: " << itr.first << " || Quantità: " << itr.second << std::endl;
      }
    }
    void add(Articolo newArticolo) {
        std::map<std::string, int>::iterator it = listaArt.begin();
        it = listaArt.find("phone");

        listaArt.insert(make_pair(newArticolo.name, (newArticolo.name,newArticolo.qty)));
    }

};


#endif //LISTASPESA_SPESA_H
