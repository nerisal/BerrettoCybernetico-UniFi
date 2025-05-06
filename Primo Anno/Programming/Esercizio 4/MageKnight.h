#ifndef E4_ABSTRACT_CLASSES_EXERCISE_MAGEKNIGHT_H
#define E4_ABSTRACT_CLASSES_EXERCISE_MAGEKNIGHT_H


// TODO must inherit from Knight and Wizard
class MageKnight {
public:
    MageKnight(const std::string &n, int d, int hp, int armor, int m);

    // TODO override move and fight

    virtual char getCharacterSymbol() const override {
        return 'M';
    }

};


#endif //E4_ABSTRACT_CLASSES_EXERCISE_MAGEKNIGHT_H
