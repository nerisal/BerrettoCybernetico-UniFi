#include <iostream>

class Weapon; // forward declaration see https://en.cppreference.com/w/cpp/language/class

class GameCharacter {
public:
    virtual int fight(GameCharacter& enemy) = 0;
    virtual void move(int x, int y) = 0;
    virtual ~GameCharacter() {} // base classes with virtual methods must have a virtual destructor
    void setWeapon(Weapon* w) {
        GameCharacter::w = w;
    }

protected:
    Weapon* w;
    int posX, posY;
};

class Weapon {
public:
    virtual int use(GameCharacter& enemy) = 0;
    virtual ~Weapon() {} // base classes with virtual methods must have a virtual destructor

protected:
    int strength;
    bool shield;
};

class RebelGuard : public GameCharacter {
public:
    int fight(GameCharacter &enemy) override {
        std::cout << "RebelGuard::fight" << std::endl;
        int result = w->use(enemy);
        return result;
    }

    void move(int x, int y) override {
        posX += x;
        posY += y;
        std::cout << "RebelGuard::move to" << posX << " - " << posY << std::endl;
    }
};

class JediKnight : public GameCharacter {
public:
    int fight(GameCharacter &enemy) override {
        int result = w->use(enemy);
        result += w->use(enemy);
        return result;
    }

    void move(int x, int y) override {
        posX += x;
        posY += y;
        std::cout << "JediKnight::move to" << posX << " - " << posY << std::endl;
    }

protected:
    int force;
};


class StormTrooper : public GameCharacter {
public:
    int fight(GameCharacter &enemy) override {
        std::cout << "StormTrooper::fight" << std::endl;
        int result = w->use(enemy);
        result--;
        return result;
    }

    void move(int x, int y) override {
        posX += x;
        posY += y;
        std::cout << "StormTrooper::move to" << posX << " - " << posY << std::endl;
    }
};

class Blaster : public Weapon {
public:
    explicit Blaster(int s) {
        strength = s;
    }
    int use(GameCharacter &enemy) override {
        std::cout << "Pew" << std::endl;
        return strength;
    }
};

class LaserSword : public Weapon {
public:
    explicit LaserSword(int s=10) {
        strength = s;
    }

    int use(GameCharacter &enemy) override {
        std::cout << "Bzzz Bzz!" << std::endl;
        return strength;
    }
};

class AbstractGameFactory {
public:
    virtual GameCharacter* createGameCharacter() = 0;
    virtual Weapon* createWeapon() = 0;
    virtual ~AbstractGameFactory() {}
};

class RebelFactory : public AbstractGameFactory {
public:
    GameCharacter* createGameCharacter() override {
        return new RebelGuard;
    }

    Weapon* createWeapon() override {
        return new Blaster(6);
    }
};

class JediFactory : public AbstractGameFactory {
public:
    GameCharacter* createGameCharacter() override {
        return new JediKnight;
    }

    Weapon* createWeapon() override {
        return new LaserSword;
    }
};

class EmpireFactory : public AbstractGameFactory {
public:
    GameCharacter* createGameCharacter() override {
        return new StormTrooper;
    }

    Weapon* createWeapon() override {
        return new Blaster(8);
    }
};

int main() {
    AbstractGameFactory* gcf = new JediFactory;
    GameCharacter* hero = gcf->createGameCharacter();
    Weapon* w = gcf->createWeapon();
    hero->setWeapon(w);
    AbstractGameFactory* gcef = new EmpireFactory;
    GameCharacter* enemy = gcef->createGameCharacter();
    Weapon* w2 = gcef->createWeapon();
    enemy->setWeapon(w2);
    hero->fight(*enemy);
    delete(hero);
    delete(enemy);
    delete(w);
    delete(w2);
    delete(gcf);
    delete(gcef);
}