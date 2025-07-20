//
// Created by Monica Eron on 08/01/18.
//

#ifndef ES4_OBSERVER_SUMFORMULA_H
#define ES4_OBSERVER_SUMFORMULA_H


#include <string>
#include <list>

#include "Cell.h"
#include "Observer.h"

class SumFormula : public Observer {
public:
    SumFormula(std::string n) : name(n) {}
    virtual ~SumFormula();

    void calc();

    void addCell( Cell* cell );
    void removeCell( Cell* cell );

    void update() override;

private:
    std::string name;
    std::list<Cell*> cells;
};



#endif //ES4_OBSERVER_SUMFORMULA_H
