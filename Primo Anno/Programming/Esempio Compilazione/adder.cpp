#include "adder.h"

int sum(int* array, int num) {
    int result = 0;
    for (int i=0; i<num; i++)
        result += array[i];
    return result;
}