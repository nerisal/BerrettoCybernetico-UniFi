#include <iostream>
#include <memory>

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
    virtual std::unique_ptr<GameCharacter> createGameCharacter() = 0;
    virtual std::unique_ptr<Weapon> createWeapon() = 0;
    virtual ~AbstractGameFactory() {}
};

class RebelFactory : public AbstractGameFactory {
public:
    std::unique_ptr<GameCharacter> createGameCharacter() override {
        return std::unique_ptr<RebelGuard>(new RebelGuard);
    }

    std::unique_ptr<Weapon> createWeapon() override {
        return std::unique_ptr<Weapon>(new Blaster(6));
    }
};

class JediFactory : public AbstractGameFactory {
public:
    std::unique_ptr<GameCharacter> createGameCharacter() override {
        return std::unique_ptr<JediKnight>(new JediKnight);
    }

    std::unique_ptr<Weapon> createWeapon() override {
        return std::unique_ptr<Weapon>(new LaserSword);
    }
};

class EmpireFactory : public AbstractGameFactory {
public:
    std::unique_ptr<GameCharacter> createGameCharacter() override {
        return std::unique_ptr<StormTrooper>(new StormTrooper);
    }

    std::unique_ptr<Weapon> createWeapon() override {
        return std::unique_ptr<Weapon>(new Blaster(8));
    }
};

int main() {
    std::unique_ptr<AbstractGameFactory> gcf(new JediFactory);
    std::unique_ptr<GameCharacter> hero = gcf->createGameCharacter();
    std::unique_ptr<Weapon> w = gcf->createWeapon();
    hero->setWeapon(w.get()); // hero just need the address to sue the weapon. It's not owning it (no delete in GameCharacter)
    std::unique_ptr<AbstractGameFactory> gcef(new EmpireFactory);
    std::unique_ptr<GameCharacter> enemy = gcef->createGameCharacter();
    std::unique_ptr<Weapon> w2 = gcef->createWeapon();
    enemy->setWeapon(w2.get());
    hero->fight(*enemy);
}