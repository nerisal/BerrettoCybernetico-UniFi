//
// Created by Martina Buccioni on 04/07/19.
//

#ifndef UNTITLED4_HOTEL_H
#define UNTITLED4_HOTEL_H

#include "Room.h"
#include <iostream>


class Hotel{
private:
    list<Room> rooms;

public:

    Hotel() {}

    virtual ~Hotel() {}

    void add(Room r){
        rooms.push_back(r);
    }


    void print_tutte_le_stanze(){
        for(auto itr:rooms){
            itr.print_info();
            cout<<endl;
        }}

    void print_stanze_libere(){

        for (auto itr:rooms){
            if(!itr.getoccupied()){
                itr.print_info();

            }
        }}

    void print_stanze(int N){
        int count=0;
        for (auto itr: rooms){
            if( !itr.getoccupied() && itr.get_numletto()>N && itr.get_numletto()<=N+1){
                itr.print_info();
                count++;


            }
        }
        cout<<endl<<"QUANTI POSTI NON SONO OCCUPATI"<<count;
    }

};

#endif //UNTITLED4_HOTEL_H
