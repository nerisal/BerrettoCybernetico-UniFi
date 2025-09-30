#include <iostream>
#include "Stack.h"
using namespace std;

int main() {
    Stack <int> intStack(3);
    intStack.pushElement(34);
    intStack.pushElement(26);
    intStack.pushElement(777);

    cout<<"Togliamo l'ultimo elemento dello stack: "<<intStack.popElement()<<endl;

    intStack.pushElement(543);
    {
        Stack <double> doubleStack;

        doubleStack.pushElement(23.65);
        doubleStack.pushElement(13.98);

        doubleStack.printElements();
    }
    intStack.pushElement(23);

    cout<<"Togliamo l'ultimo elemento dello stack: "<<intStack.popElement()<<endl;

    intStack.printElements();

}