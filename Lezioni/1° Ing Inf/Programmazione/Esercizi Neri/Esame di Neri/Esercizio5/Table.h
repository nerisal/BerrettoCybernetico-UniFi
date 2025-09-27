//
// Created by neri on 23/07/25.
//

#ifndef TABLE_H
#define TABLE_H



class Table {
private:
    int number;
    int capacity;
    bool is_free;
public:
    Table(int number, int capacity) : number(number), capacity(capacity), is_free(true) {}

    int getNumber() { return number; }
    int getCapacity() { return capacity; }
    bool isFree() { return is_free; }

    void setNumber(int n) { number = n; }
    void setCapacity(int c) { capacity = c; }
    void setIsFree(bool is) { is_free = is; }
};



#endif //TABLE_H
