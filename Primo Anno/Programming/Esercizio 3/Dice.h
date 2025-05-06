#ifndef E2_CLASS_EXERCISE_DICE_H
#define E2_CLASS_EXERCISE_DICE_H


class Dice {
public:
    explicit Dice(int f = 6);

    int roll(int r);

private:
    int faces;
    static int numRolls;
    const int maxRolls = 1000; // max number of rolls, when numRolls > maxRolls reinit RNG seed
};


#endif //E2_CLASS_EXERCISE_DICE_H
