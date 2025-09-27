//
// Created by m3ta on 7/4/2018.
//

#ifndef ABSTRACT_GAMECHARACTERFACTORY_H
#define ABSTRACT_GAMECHARACTERFACTORY_H

#include "JediKnight.h"
#include "RebelGuard.h"
#include "StormTrooper.h"
#include "AbstractFactory.h"

class GameCharacterFactory : public AbstractFactory{
public:
    virtual GameCharacter* createCharacter(std::string charType) override{
        GameCharacter* gameChar;
        if(charType.compare("j") ==  0){
            gameChar = new JediKnight;
            std::cout << "Jedi knight created" << std::endl;
        }
        else if(charType.compare("r") == 0){
            gameChar = new RebelGuard;
            std::cout << "Rebel guard created." << std::endl;
        }
        else if(charType.compare("s") == 0){
            gameChar = new StormTrooper;
            std::cout << "Storm trooper created." << std::endl;
        }
        else {
            gameChar = nullptr;
            std::cout << "No character is created." << std::endl;
        }
        return gameChar;
    }
    virtual Weapon* createWeapon(std::string weaponType) override{
    }
};


#endif //ABSTRACT_GAMECHARACTERFACTORY_H
