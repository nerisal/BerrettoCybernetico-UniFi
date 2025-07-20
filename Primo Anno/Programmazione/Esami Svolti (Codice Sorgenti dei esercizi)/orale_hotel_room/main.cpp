#include <iostream>
#include "Room.h"
#include "Hotel.h"


int main() {

    Room R(2,3);
    Room R_2(2,4,true);
    Hotel H;
    H.add(R);
    H.add(R_2);

    cout<<"STANZE CON N POSTI"<<endl;
    H.print_stanze(1);
    cout<<endl;
    cout<<"STANZE LIBERE:"<<endl;
    H.print_stanze_libere();
    cout<<"STANZE CON N POSTI:"<<endl;
    cout<<endl;
    H.print_tutte_le_stanze();

}