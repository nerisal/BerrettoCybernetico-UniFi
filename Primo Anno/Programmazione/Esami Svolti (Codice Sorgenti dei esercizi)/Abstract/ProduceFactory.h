//
// Created by m3ta on 7/4/2018.
//

#ifndef ABSTRACT_PRODUCEFACTORY_H
#define ABSTRACT_PRODUCEFACTORY_H

#include "AbstractFactory.h"
#include "GameCharacterFactory.h"
#include "WeaponFactory.h"

class ProduceFactory{
public:
    AbstractFactory* getFactory(std::string factoryType){
        if(factoryType.compare("c")==0) {
            std::cout << "Character factory selected." << std::endl;
            return new GameCharacterFactory;
        } else if(factoryType.compare("w") == 0){
            std::cout << "Weapon factory selected." << std::endl;
            return new WeaponFactory;
        }
        std::cerr << "No factory created!" << std::endl;
        return nullptr;
    }

};


#endif //ABSTRACT_PRODUCEFACTORY_H
