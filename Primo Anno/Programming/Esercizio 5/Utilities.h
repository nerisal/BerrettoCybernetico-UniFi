#ifndef UTILITIES_H
#define UTILITIES_H

#include <cstdlib>

// Qui si implementa il template di funzione

// DONE implement a l1Distance() template function returning the L1 distance of two objects
// return int computed as:
// int distance = abs(p.getPosX() - q.getPosX()) + abs(p.getPosY() - q.getPosY());

template <typename T1, typename T2>
int l1Distance(const T1& obj1, const T2& obj2) {
  int distance;
  return distance = abs(obj1.getPosX() - obj2.getPosX()) + abs(obj1.getPosY() - obj2.getPosY());
}


#endif //UTILITIES_H
