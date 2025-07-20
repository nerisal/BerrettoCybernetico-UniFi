#include <iostream>

#include "SumFormula.h"

int main() {
	Cell a1;
	Cell a2;
	Cell b1;

	SumFormula f1("f1");
	SumFormula f2("f2");

    a1.printObservers();
    a2.printObservers();
    b1.printObservers();

	f1.addCell(&a1);
	f1.addCell(&b1);

    a1.notify();

    a1.printObservers();
    a2.printObservers();
    b1.printObservers();

	f2.addCell(&a2);
	f2.addCell(&b1);

	a1.setValue(1.2);
	a2.setValue(3.14);
	b1.setValue(2.3);

	f1.removeCell(&a1);

    a1.printObservers();

	//f2.addCell(&a1);

	a1.setValue(1.0);

    a1.printObservers();
    a2.printObservers();
    b1.printObservers();
}
