#include <iostream>
#include <vector>

#include "Dungeon.h"
#include "GameCharacter.h"
#include "Wizard.h"
#include "Knight.h"
#include "MageKnight.h"
#include "Sword.h"
#include "Bow.h"
#include "Orc.h"
#include "Vault.h"
#include "Potion.h"
#include "Utilities.h"
#include "Dice.h"
#include "Skeleton.h"
#include "splash_screen.h"

// enum class game event
enum class GameEvent {
    quit, left, up, down, right, fight, magic, noop
};

// enum class player type
enum class PlayerType {
    KNIGHT, WIZARD, MAGE_KNIGHT
};

// poll event from keyboard
GameEvent getEvent() {
    char c;
    while (std::cin.get(c)) {
        std::cin.ignore(100, '\n');
        switch (c) {
            case 'Q':
                return GameEvent::quit;
            case 'w':
                return GameEvent::up;
            case 'a':
                return GameEvent::left;
            case 's':
                return GameEvent::down;
            case 'd':
                return GameEvent::right;
            case 'f':
                return GameEvent::fight;
            case 'm':
                return GameEvent::magic;
            default:
                return GameEvent::noop;
        }
    }
    return GameEvent::noop;
}

// compute if a cell at x,y coordinates can host a game character
bool isLegalCell(int x, int y, const Dungeon &map) {
    switch (map.getCell(x, y)) {
        case TileType::Unused:
            return false;
        case TileType::DirtWall:
            return false;
        case TileType::DirtFloor:
            return true;
        case TileType::StoneWall:
            return false;
        case TileType::Corridor:
            return true;
        case TileType::Door:
            return true;
        case TileType::UpStairs:
            return true;
        case TileType::DownStairs:
            return true;
        case TileType::Chest:
            return false;
        default:
            return false;
    };
}

// find a cell starting from x,y that can host a game character
bool findFreeMapTile(int &x, int &y, const Dungeon &map, std::vector<GameCharacter*>* gameCharacters = nullptr) {
    for (int i = x; i < map.getXsize(); i++) {
        for (int j = y; j < map.getYsize(); j++) {
            if (map.getCell(i, j) == TileType::DirtFloor) {
                x = i;
                y = j;
                // additional check
                if (gameCharacters) {
                    for (auto gc : *gameCharacters) {
                        if (gc->getPosY() == y && gc->getPosX() == x)
                            return false;
                    }
                }
                return true;
            }
        }
    }
    return false;
}


/* FIXME add return value */ createMonsters(int startX, int startY, const int numMonsters, const Dungeon &map) {
    // FIXME add a vector that may contain any monster, call it result
    // FIXME reserve numMonsters elements in the vector
    Dice monsterTypeDice(2);
    Dice relPositionDispl(10);
    for(int i=0; i<numMonsters; i++) {
        GameCharacter* enemy;
        if(monsterTypeDice.roll(1)==1)
            enemy = new Orc(20);
        else
            enemy = new Skeleton(5);

        int flipSearch = 0;
        bool positionFound = false;
        int monsterPositionX = startX;
        int monsterPositionY = startY;
        while(!positionFound) {
            if (flipSearch%7==0) {
                monsterPositionX = startX+1;
                monsterPositionY = startY+1;
            }
            if(flipSearch%2) {
                monsterPositionX += relPositionDispl.roll(1+flipSearch);
                monsterPositionY += relPositionDispl.roll(1+flipSearch);
                flipSearch++;
            } else {
                monsterPositionX -= relPositionDispl.roll(1+flipSearch);
                monsterPositionY -= relPositionDispl.roll(1+flipSearch);
                flipSearch++;
            }
            if( monsterPositionX<0 || monsterPositionX>map.getXsize())
                monsterPositionX = startX+1;
            if( monsterPositionY<0 || monsterPositionY>map.getYsize())
                monsterPositionY = startY+1;
            positionFound = findFreeMapTile(monsterPositionX, monsterPositionY, map, &result);
            if (monsterPositionX == startX && monsterPositionY == startY)
                positionFound = false;
        }
        enemy->setPosX(monsterPositionX);
        enemy->setPosY(monsterPositionY);
        // FIXME add a new monster to the vector
    }
    return result;
}


bool checkEnemyPositions(int heroX, int heroY, std::vector<GameCharacter*> &enemies) {
    bool result = false;
    for(auto enemy : enemies) {
        if(heroX == enemy->getPosX() && heroY == enemy->getPosY())
            result = true;
    }
    return result;
}


GameCharacter& selectEnemy(GameCharacter &hero, std::vector<GameCharacter*> &enemies) {
    int maxDistance = 1;
    for(auto enemy : enemies)
        if ((abs(hero.getPosX() - enemy->getPosX()) <= maxDistance) || (abs(hero.getPosX() - enemy->getPosY()) <= maxDistance))
            return *enemy;
}

// evaluate if a game character move is legal (e.g. the hero is not walking through walls)
bool isLegalMove(GameCharacter &hero, int dX, int dY, const Dungeon &map, std::vector<GameCharacter*> &enemies) {
    int newX = hero.getPosX() + dX;
    int newY = hero.getPosY() + dY;
    bool enemyPos = checkEnemyPositions(newX, newY, enemies);
    return (isLegalCell(newX, newY, map) && !enemyPos);
}


// update game status depending on player's action
bool updateGame(const GameEvent &gameEvent, GameCharacter &hero, std::vector<GameCharacter*> &enemies,
                const Dungeon &map) {
    switch (gameEvent) {
        case GameEvent::quit: //
            return true;
        case GameEvent::up: {
            // graphics coordinates: (0,0) is top-left
            if (isLegalMove(hero, 0, -1, map, enemies))
                hero.move(0, -1);
            break;
        }
        case GameEvent::left: {
            if (isLegalMove(hero, -1, 0, map, enemies))
                hero.move(-1, 0);
            break;
        }
        case GameEvent::down: {
            // graphics coordinates: (0,0) is top-left
            if (isLegalMove(hero, 0, 1, map, enemies))
                hero.move(0, 1);
            break;
        }
        case GameEvent::right: {
            if (isLegalMove(hero, 1, 0, map, enemies))
                hero.move(1, 0);
            break;
        }
        case GameEvent::fight: {
            if (hero.isLegalFight(enemies)) {
                std::cout << "Fight" << std::endl;
                GameCharacter& selectedEnemy = selectEnemy(hero, enemies);
                int result = hero.fight(selectedEnemy);
                if (result) {
                    std::cout << "Enemy hit ! (HP: " << selectedEnemy.getHP() << ")" << std::endl;
                    if (selectedEnemy.getHP()<=0)
                        std::cout << "Enemy is dead." << std::endl;
                } else
                    std::cout << "Hit missed..." << std::endl;
            } else {
                std::cout << "Enemy too far, can not fight" << std::endl;
            }
            break;
        }
        case GameEvent::magic: {
            if (MageKnight* m = dynamic_cast<MageKnight*>(&hero)) {
                if (hero.isLegalFight(enemies))
                    m->doMagic();
                else
                    std::cout << "Enemy too far, can't do magic" << std::endl;
            } else if (Wizard* w = dynamic_cast<Wizard*>(&hero))
                w->doMagic();
            break;
        }
        case GameEvent::noop: {
            std::cout << "Press: w,a,s,d,f,m or Q to quit." << std::endl;
            break;
        }
    }
    return false;
}


// render Head Up Display
void renderHUD(GameCharacter &hero) {
    std::cout << "Press: w,a,s,d,f";
    if (typeid(hero) == typeid(Wizard) || typeid(hero) == typeid(MageKnight))
        std::cout << ",m"; // only Wizards can do magic
    std::cout << " or Q to quit." << std::endl;
    std::cout << "Hero - HP: " << hero.getHP() << " - armor: " << hero.getArmor();
    if (hero.getWeapon() != nullptr)
        std::cout << " - Weapon strength: " << hero.getWeapon()->getStrength();
    std::cout << " - Hero type: ";
    if (typeid(hero) == typeid(Knight))
        std::cout << " Knight.";
    else if (typeid(hero) == typeid(Wizard))
        std::cout << " Wizard.";
    else if (typeid(hero) == typeid(MageKnight))
        std::cout << " MageKnight.";
    else
        std::cout << " Unknown.";
    std::cout << std::endl;
}

bool checkMonsterPosition(int x, int y, /* FIXME what is the type of enemies ? */ &enemies, char &renderSymbol) {
    /* FIXME add a for cycle to process each monster in the vector */ {
        if (enemy->getHP()<=0)
            return false;
        if (x == enemy->getPosX() && y == enemy->getPosY()) {
            renderSymbol = enemy->getCharacterSymbol(); // XXX polymorphism in action
            return true;
        }
    }
    return false;
}

// render the whole graphics, compositing characters over map
void renderGame(Dungeon &map, GameCharacter &hero, std::vector<GameCharacter*> &enemies) {
    for (int y = 0; y < map.getYsize(); y++) {
        for (int x = 0; x < map.getXsize(); x++) {
            // draw characters... hero and monster
            char renderSymbol = ' ';
            if (x == hero.getPosX() && y == hero.getPosY())
                std::cout << hero.getCharacterSymbol();
            else if (checkMonsterPosition(x, y, enemies, renderSymbol))
                std::cout << renderSymbol;
            else {
                // alternatively draw map tile
                std::string tileSymbol = TileTypeToTileString(map.getCell(x, y));
                std::cout << tileSymbol;
            }
        }
        std::cout << std::endl;
    }
}


int main() {
    // TODO should we manage the exceptions here ?
    // or in displaySplash?
    displaySplash();
    // create map
    Dungeon map;
    map.createDungeon(80, 25, 50);
    std::string firstMap = "./res/start_map.txt";

    // TODO manage all possible exceptions: GameFileException, out_of_range, runtime_error
    map.saveToFile(firstMap);
    map.createDungeon(80, 25, 50);
    map.saveToFile("./res/secret_map.txt");
    map.loadFromFile(firstMap); // XXX should work
    //map.loadFromFile("non_existing_map.txt"); // XXX should throw GameFileException
    //map.loadFromFile("./res/start_map_corrupted.txt"); // XXX should throw std::out_of_range
    //map.loadFromFile("./res/start_map_corrupted2.txt"); // XXX should throw std::runtime_error
    // TODO if GameFileException print error messages and if fatal abort()
    // if runtime_error | out_of_range print error messages and abort()

    // create hero and set him/her up
    GameCharacter* hero;
    PlayerType playerType = PlayerType::MAGE_KNIGHT;
    switch (playerType) {
        case PlayerType::KNIGHT:
            hero = new Knight("Isildur", 34);
            break;
        case PlayerType::WIZARD:
            hero = new Wizard("Gandalf", 35);
            break;
        case PlayerType::MAGE_KNIGHT:
            hero = new MageKnight("Boromir", 35, 20, 12, 5);
            break;
    }
    // find a legal start position
    int startX = 0;
    int startY = 0;
    findFreeMapTile(startX, startY, map, nullptr);
    hero->setPosX(startX);
    hero->setPosY(startY);
    Vault<Weapon*> armory(startX+1, startY);
    Sword* aSword1 = new Sword(12, false, true);
    Bow* aBow1 = new Bow(18, 40, true);
    Sword* aSword2 = new Sword(15, true, true);
    armory.setElement(0, aSword1);
    armory.setElement(1, aBow1);
    armory.setElement(2, aSword2);
    if (l1Distance(*hero, armory)<2) {
        armory.open();
        armory.printContent();
    }

    Inventory<Potion> backPack;
    Potion aPotion1;
    Potion aPotion2(PotionType::HEALING_HP);
    backPack.setElement(0, aPotion1);
    backPack.setElement(1, aPotion2);
    backPack.printContent();

    // create a weapon and give it to hero
    bool useSword = true;
    Weapon* heroWeapon;
    if (useSword)
        heroWeapon = new Sword(20);
    else
        heroWeapon = new Bow(32);
    hero->setWeapon(heroWeapon);
    // create an enemy (an Orc or a Skeleton)
    const int NUM_MONSTERS = 3;
    /* FIXME create a vector called enemies that can contain any type of monsters */ = createMonsters(hero->getPosX(), hero->getPosY(), NUM_MONSTERS, map);

    // render
    renderHUD(*hero);
    renderGame(map, *hero, enemies);
    // game loop. See http://gameprogrammingpatterns.com/game-loop.html
    while (true) {
        // poll event
        GameEvent gameEvent = getEvent();

        // update game status
        bool quit = updateGame(gameEvent, *hero, enemies, map);
        if (quit)
            return 0;
        // render
        renderHUD(*hero);
        renderGame(map, *hero, enemies);
    }

}

