#include <iostream>

#include "Dungeon.h"
#include "GameCharacter.h"
#include "Wizard.h"
#include "Knight.h"
#include "MageKnight.h"
#include "Sword.h"
#include "Bow.h"
#include "Orc.h"

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
bool setupCharacterCell(int &x, int &y, const Dungeon &map) {
    for (int i = x; i < map.getXsize(); i++) {
        for (int j = y; j < map.getYsize(); j++) {
            if (map.getCell(i, j) == TileType::DirtFloor) {
                x = i;
                y = j;
                return true;
            }
        }
    }
    return false;
}

// evaluate if a game character move is legal (e.g. the hero is not walking through walls)
bool isLegalMove(GameCharacter &hero, int dX, int dY, const Dungeon &map, GameCharacter &enemy) {
    int newX = hero.getPosX() + dX;
    int newY = hero.getPosY() + dY;
    return (isLegalCell(newX, newY, map) && (newX != enemy.getPosX() || newY != enemy.getPosY()));
}


// update game status depending on player's action
bool updateGame(const GameEvent &gameEvent, GameCharacter &hero, GameCharacter &enemy, const Dungeon &map) {
    switch (gameEvent) {
        case GameEvent::quit: //
            return true;
        case GameEvent::up: {
            // graphics coordinates: (0,0) is top-left
            if (isLegalMove(hero, 0, -1, map, enemy))
                hero.move(0, -1);
            break;
        }
        case GameEvent::left: {
            if (isLegalMove(hero, -1, 0, map, enemy))
                hero.move(-1, 0);
            break;
        }
        case GameEvent::down: {
            // graphics coordinates: (0,0) is top-left
            if (isLegalMove(hero, 0, 1, map, enemy))
                hero.move(0, 1);
            break;
        }
        case GameEvent::right: {
            if (isLegalMove(hero, 1, 0, map, enemy))
                hero.move(1, 0);
            break;
        }
        case GameEvent::fight: {
            if (hero.isLegalFight(enemy)) {
                std::cout << "Fight" << std::endl;
                int result = hero.fight(enemy);
                if (result) {
                    std::cout << "Enemy hit ! (HP: " << enemy.getHP() << ")" << std::endl;
                } else
                    std::cout << "Hit missed..." << std::endl;
            } else {
                std::cout << "Enemy too far, can not fight" << std::endl;
            }
            break;
        }
        case GameEvent::magic: {
            // TODO RTTI to check if Wizard and then allow doMagic()
            if (typeid(hero) == typeid(Wizard))
                dynamic_cast<Wizard&>(hero).doMagic();
            // if MageKnight then allow doMagic only if isLegalFight is true
            // XXX a MageKnight is_a Wizard !

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
    // TODO print m also if hero is a MageKnight
    if (typeid(hero) == typeid(Wizard))
        std::cout << ",m"; // only Wizards can do magic
    std::cout << " or Q to quit." << std::endl;
    std::cout << "Hero - HP: " << hero.getHP() << " - armor: " << hero.getArmor();
    if (hero.getWeapon() != nullptr)
        std::cout << " - Weapon strength: " << hero.getWeapon()->getStrength();
    std::cout << " - Hero type: ";
    // DONE check type of hero and print corresponding string
    if (typeid(hero) == typeid(Wizard)){
        std::cout << "Wizard";

    }else if (typeid(hero) == typeid(Knight)) {
        std::cout << "Knight";
    }


    std::cout << std::endl;
}

bool checkMonsterPosition(int x, int y, const GameCharacter &enemy, char &renderSymbol) {
    if (x == enemy.getPosX() && y == enemy.getPosY()) {
        renderSymbol = enemy.getCharacterSymbol(); // XXX polymorphism in action
        return true;
    }
    return false;
}

// render the whole graphics, compositing characters over map
void renderGame(Dungeon &map, GameCharacter &hero, GameCharacter &enemy) {
    for (int y = 0; y < map.getYsize(); y++) {
        for (int x = 0; x < map.getXsize(); x++) {
            // draw characters... hero and monster
            char renderSymbol = ' ';
            if (x == hero.getPosX() && y == hero.getPosY())
                std::cout << hero.getCharacterSymbol();
            else if (checkMonsterPosition(x, y, enemy, renderSymbol))
                std::cout << renderSymbol;
            else {
                // alternatively draw map tile
                switch (map.getCell(x, y)) {
                    case TileType::Unused:
                        std::cout << " ";
                        break;
                    case TileType::DirtWall:
                        std::cout << "+";
                        break;
                    case TileType::DirtFloor:
                        std::cout << ".";
                        break;
                    case TileType::StoneWall:
                        std::cout << "O";
                        break;
                    case TileType::Corridor:
                        std::cout << "#";
                        break;
                    case TileType::Door:
                        std::cout << "D";
                        break;
                    case TileType::UpStairs:
                        std::cout << "<";
                        break;
                    case TileType::DownStairs:
                        std::cout << ">";
                        break;
                    case TileType::Chest:
                        std::cout << "*";
                        break;
                };
            }
        }
        std::cout << std::endl;
    }
}


int main() {
    // create map
    Dungeon map;
    map.createDungeon(80, 25, 50);
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

            // TODO create a MageKnight with the following params: "Boromir", 35, 20, 12, 5
    }
    // find a legal start position
    int startX = 0;
    int startY = 0;
    setupCharacterCell(startX, startY, map);
    hero->setPosX(startX);
    hero->setPosY(startY);
    // create a weapon and give it to hero
    bool useSword = true;
    Weapon* heroWeapon;
    if (useSword)
        heroWeapon = new Sword(20);
    else
        heroWeapon = new Bow(32);
    hero->setWeapon(heroWeapon);
    // create an enemy (an Orc or a Skeleton)
    GameCharacter* enemy;
    enemy = new Orc(12);
    // find monster position not too far from hero position
    startX += 5;
    startY += 3;
    setupCharacterCell(startX, startY, map);
    enemy->setPosX(startX);
    enemy->setPosY(startY);

    // render
    renderHUD(*hero);
    renderGame(map, *hero, *enemy);
    // game loop. See http://gameprogrammingpatterns.com/game-loop.html
    while (true) {
        // poll event
        GameEvent gameEvent = getEvent();

        // update game status
        bool quit = updateGame(gameEvent, *hero, *enemy, map);
        if (quit)
            return 0;
        // render
        renderHUD(*hero);
        renderGame(map, *hero, *enemy);
    }

}
