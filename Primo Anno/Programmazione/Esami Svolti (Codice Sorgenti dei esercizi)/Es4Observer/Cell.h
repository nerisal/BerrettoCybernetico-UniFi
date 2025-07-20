//
// Created by Monica Eron on 08/01/18.
//

#ifndef ES4_OBSERVER_CELL_H
#define ES4_OBSERVER_CELL_H

#include "Subject.h"
#include "SumFormula.h"

class Cell : public Subject {
public:
    explicit Cell(float v=0) : value(v){}
    float getValue() const {
        return value;
    }
    void setValue(float v){
        value=v;
        std::cout<< "Aggiorno valore di cella "<<std::endl;
        notify();
    }
    virtual void notify(){
        for(auto itr=obs.begin();itr!=obs.end();itr++)
            (*itr)->update();
    }
    virtual void subscribe(Observer* o){ //registra observer
        obs.push_back(o);
    }
    virtual void unsubscribe(Observer* o){ //rimuove observer
        obs.remove(o);
    }
    void printObservers(){
        std::cout<<"Gli observer della cella sono:"<<std::endl;
        if(!obs.empty()) {
            for (auto itr = obs.begin(); itr != obs.end(); itr++)
                std::cout << (*itr)<< std::endl;
        }else std::cout << "Non ce ne sono!"<< std::endl;
    }
private:
    float value;
    std::list<Observer* > obs;
};

#endif //ES4_OBSERVER_CELL_H
