#include <iostream>
#include "Spesa.h"


int main() {

    Articolo articolo1;
    articolo1.name="Smartphone";
    articolo1.qty=1;

    Spesa spesa;

    spesa.add(articolo1);
    //spesa.printAll();

    Articolo articolo2;
    articolo2.name="phone";
    articolo2.qty=1;
    Articolo articolo3;
    articolo2.name="phone";
    articolo2.qty=1;
    spesa.add(articolo2);
    spesa.add(articolo3);
    spesa.printAll();


    return 0;
}