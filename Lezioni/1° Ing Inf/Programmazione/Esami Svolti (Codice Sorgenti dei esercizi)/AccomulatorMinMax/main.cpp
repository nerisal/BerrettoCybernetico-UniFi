#include <iostream>

#include <iostream>
#include "AccumulatorMinMax.h"

int main () {
    int a = 10;
    int b = 12;
    int c = 15;

    int g = 0;

    float d = 27.5;
    float e = 48.5;
    float f = 60.5;

    float h = 0;

    AccumulatorMinMax<int> list1;
    list1.addElement(&a);
    list1.addElement(&b);

    //g = list1.getMax();
    std::cout << "Il max nella list1 :" << list1.getMax() << std::endl;

    list1.addElement(&c);

    g = list1.getMax();
    std::cout << "Il max nella list1 :" << g << std::endl;

    g = list1.getMin();
    std::cout << "Il min nella list1 :" << g << std::endl;

    AccumulatorMinMax<float> list2;
    list2.addElement(&e);
    list2.addElement(&f);

    h = list2.getMin();
    std::cout << "Il min nella list2 :" << h << std::endl;

    list2.addElement(&d);

    h = list2.getMin();
    std::cout << "Il min nella list2 :" << h << std::endl;

    h = list2.getMax();
    std::cout << "Il max nella list2 :" << h << std::endl;

    return 0;
}