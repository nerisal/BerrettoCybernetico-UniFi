//
// Created by Martina Buccioni on 04/07/19.
//

#ifndef UNTITLED4_ROOM_H
#define UNTITLED4_ROOM_H

#include <iostream>
#include <list>
using namespace std;
class Room{
private:
    int num_letti;
    int num_camera;
    bool occupied;
public:
    Room(int num_letti, int num_camera, bool occupied=false) : num_letti(num_letti), num_camera(num_camera),
                                                         occupied(occupied) {}

    virtual ~Room() {}

    void print_info()
    {
        cout<<"NUMERO CAMERA"<<num_camera<<endl;
        cout<<"NUMERO DI LETTI"<<num_letti<<endl;
        cout<<"E' OCCUPATA?"<<occupied;
    }
    bool getoccupied(){
        return occupied;
    }
    void set_occupied(bool o){
        occupied=o;
    }
    int get_numletto(){
        return num_letti;
    };
    void set_numeltto(int num){
        num_letti=num;
    }
};


#endif //UNTITLED4_ROOM_H
