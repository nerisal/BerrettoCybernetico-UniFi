#ifndef E2_CLASS_EXERCISE_DICE_H
#define E2_CLASS_EXERCISE_DICE_H


class Dice {
public:
    Dice();
    explicit Dice(int f = 6);
    int roll(int r) const;

private:
    int faces;
    static int rollsCount;
    const int ROLLS_LIMIT = 100;
};


#endif //E2_CLASS_EXERCISE_DICE_H
