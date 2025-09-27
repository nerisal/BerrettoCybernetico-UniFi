#include <iostream>
#include <string>
#include "ProduceFactory.h"


int main() {

    //Getting weapon factory through produce factory
    ProduceFactory* produceFactory = new ProduceFactory;

    AbstractFactory* weaponFactory = new WeaponFactory;
    weaponFactory = produceFactory->getFactory("w");

    //Getting weapons
    Weapon* blaster = new Blaster(6);
    blaster = weaponFactory->createWeapon("b");
    blaster->use();

    Weapon* laserSword = new LaserSword;
    laserSword = weaponFactory->createWeapon("l");
    laserSword->use();
    std::cout << std::endl;
    //Getting game character factory through produce Factory
    AbstractFactory* gameCharacterFactory = new GameCharacterFactory;
    gameCharacterFactory = produceFactory->getFactory("c");

    //Getting characters
    GameCharacter* jediKnight = new JediKnight("Jedi knigth", nullptr);
    jediKnight = gameCharacterFactory->createCharacter("j");
    jediKnight->move(5,5);

    GameCharacter* rebelGuard = new RebelGuard("Rebel Guard", nullptr);
    rebelGuard = gameCharacterFactory->createCharacter("r");
    rebelGuard->move(4,5);

    GameCharacter* stormTrooper = new StormTrooper("Storm Trooper", nullptr);
    stormTrooper = gameCharacterFactory->createCharacter("s");
    stormTrooper->move(2,3);
    std::cout << std::endl;

    jediKnight->fight(*rebelGuard);
    rebelGuard->fight(*jediKnight);

    /*
        ProduceFactory* produceFactory = new ProduceFactory;
        std::string ftype;

     * do {
        std::cout << "\tCreate character or weapon (c,w): ";
        std::cin >> ftype;
        if((ftype != "c") && (ftype != "w"))
            std::cout << "Invalid choice. Please select again!" << std::endl;
    }while((ftype != "c") && (ftype != "w"));

    if(ftype.compare("w") == 0) {
        AbstractFactory* weaponFactory = new WeaponFactory;
        weaponFactory = produceFactory->getFactory(ftype);
        std::string stype;
        wrongW:
        std::cout << "\t\t[AVAILABLE WEAPONS]" << std::endl;
        std::cout << "\t\t-------------------" << std::endl;
        std::cout << "[1] Blaster\n[2] Laser Sowrd" << std::endl;
        std::cout << "Info: [Laser sword is reserver only for jedi knight]" << std::endl;
        std::cout << "\n\t\tEnter your choice (b,l): "; std::cin >> stype;
        if(stype.compare("b") == 0){
            Weapon* blaster = new Blaster;
            blaster = weaponFactory->createWeapon(stype);
        } else if(stype.compare("l") == 0){
            Weapon* laserSword = new LaserSword;
            laserSword = weaponFactory->createWeapon(stype);
        }else {
            std::cout << "Invalid weapon choice please select again!" << std::endl;
            goto wrongW;
        }

    }else if(ftype.compare("c") == 0){
        AbstractFactory* gameCharacterFactort = new GameCharacterFactory;
        gameCharacterFactort = produceFactory->getFactory(ftype);
        std::string ctype;
        wrongC:
        std::cout << "\t\t[AVAILABLE CHARACTERS]" << std::endl;
        std::cout << "\t\t----------------------" << std::endl;
        std::cout << "[1] Jedi Knight\n[2] Rebel Guard\n[3] Storm Trooper" << std::endl;
        std::cout << "Info: [Storm trooper is an enemy]" << std::endl;
        std::cout << "\n\t\tEnter your choice (j,r,s): "; std::cin >> ctype;
        if(ctype.compare("j") == 0){
            GameCharacter* jedi = new JediKnight;
            jedi = gameCharacterFactort->createCharacter(ctype);
        }else if(ctype.compare("r") == 0){
            GameCharacter* rebel = new RebelGuard;
            rebel = gameCharacterFactort->createCharacter(ctype);
        }else if(ctype.compare("s") == 0){
            GameCharacter* storm = new StormTrooper;
            storm = gameCharacterFactort->createCharacter(ctype);
        }else{
            std::cout << "Invalid choice please select again!" << std:: endl;
            goto wrongC;
        }
    }



 /*   ProduceFactory* produceFactory = new ProduceFactory;
    AbstractFactory* characterFactory = new GameCharacterFactory;
    characterFactory = produceFactory->getFactory("character");
    GameCharacter* cha = new JediKnight;
    //jedi = characterFactory->createCharacter("jedi");
    //StormTrooper stormTrooper;
    //jedi->fight(stormTrooper);
*/


    return 0;
}