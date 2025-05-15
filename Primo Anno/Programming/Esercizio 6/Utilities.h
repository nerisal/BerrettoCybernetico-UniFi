#ifndef UTILITIES_H
#define UTILITIES_H

#include <cstdlib>

template <typename T, typename U>
int l1Distance(const T &p, const U &q) {
    int distance = abs(p.getPosX() - q.getPosX()) + abs(p.getPosY() - q.getPosY());
    return distance;
};

#endif //UTILITIES_H
