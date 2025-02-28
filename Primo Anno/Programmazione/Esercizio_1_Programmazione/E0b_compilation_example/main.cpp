#include <iostream>
#include "greeter.h"
#include "adder.h"

int main() {
    sayHello("Joe Mama");
    int *array;
    int arraySize = 10;
    array = (int *) malloc(arraySize * sizeof(int));
    for (int i = 0; i < arraySize; i++)
        array[i] = i;
    std::cout << sum(array, arraySize) << std::endl;
    free(array);
    return 0;
}
