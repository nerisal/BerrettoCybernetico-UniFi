//
// Created by Monica Eron on 08/01/18.
//

#include <iostream>
#include "SumFormula.h"
#include "Cell.h"


SumFormula::~SumFormula() {
    cells.clear();
}

void SumFormula::calc(){
    float result = 0.;
    for ( auto itr = cells.begin(); itr != cells.end(); itr++ ){
        result += (*itr)->getValue();
    }
    std::cout<<"Somma totale di " << name << " : " << result << std::endl;
}

void SumFormula::addCell( Cell* cell ){
    cells.push_back(cell);
    cell->subscribe(this);
    std::cout<< "Aggiunta di una cella di valore "<< cell->getValue()<<" da " << name <<std::endl;
    update();
}

void SumFormula::removeCell( Cell* cell ){
    cells.remove(cell);
    cell->unsubscribe(this);
    std::cout<<"Rimozione di una cella di valore "<< cell->getValue() <<" da " << name <<std::endl;
    update();
}

void SumFormula::update() {
    calc();
}