#ifndef DICE_H
#define DICE_H


class Dice {
public:
    explicit Dice(int f = 6);

    int roll(int r);

private:
    int faces;
    static int numRolls;
    const int maxRolls = 1000; // max number of rolls, when numRolls > maxRolls reinit RNG seed
};


#endif //DICE_H
