#ifndef CHARACTER_H_
#define CHARACTER_H_

#include "Weapon.h"

class GameCharacter {
 public:
  GameCharacter();
  explicit GameCharacter(int hp, int a = 10);
  virtual ~GameCharacter();  // XXX polymorphic destructor !

  GameCharacter(const GameCharacter &original);  // FIXME: handle ABC copy
  GameCharacter &operator=(
      const GameCharacter &right);  // FIXME: handle ABC copy

  virtual void move(int x,
                    int y);  // we want to override it: it must be virtual

  // we want to override it: it must be virtual
  virtual char getCharacterSymbol() const { return 'C'; }

  // DONE declare a pure virtual fight(GameCharacter &enemy) returning int
  virtual int fight(GameCharacter &enemy) = 0;

  bool isLegalFight(const GameCharacter &enemy) const;

  virtual int receiveDamage(
      int points);  // we want to override it: must be virtual

  static int l1Distance(const GameCharacter &p, const GameCharacter &q);

  int getPosX() const { return posX; }
  void setPosX(int posX) { GameCharacter::posX = posX; }
  int getPosY() const { return posY; }
  void setPosY(int posY) { GameCharacter::posY = posY; }

  int getHP() const;
  void setHP(int hp);

  Weapon *getWeapon();
  void setWeapon(Weapon *weapon);

  int getArmor() const;
  void setArmor(int defense);

  int getMovements() const;
  void setMovements(int movements);

  // easier to access in derived classes if protected
 protected:
  int HP;
  int armor;
  int movements;
  int posX;
  int posY;
  Weapon *weapon;

  int basicFight(GameCharacter &enemy);  // basic utility implementation
};

#endif  // CHARACTER_H_
