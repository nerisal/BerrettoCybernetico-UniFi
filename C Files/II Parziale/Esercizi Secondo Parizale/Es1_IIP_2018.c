#include <stdio.h>
#include <stdlib.h>

typedef unsigned short int boolean;
#define TRUE 1
#define FALSE 0

struct record {
    int value;
    int next;
};

struct list {
    struct record *buffer;
    int size;
    int first;
    int free;
};

void init(struct list *ptr, int size);
boolean suf_insert(struct list *ptr, int value);

int main() {

    return 0;
}

void init(struct list *ptr, int size) {
    ptr->buffer = (struct record *)malloc(sizeof(struct record) * size);
    ptr->size = size;
    ptr->first = size;
    ptr->free = 0;

    for (int count = 0; count < size; count++) {
        ptr->buffer[ptr->free].next = count + 1;
    }
}

boolean suf_insert(struct list *ptr, int value) {
    int count = ptr->first;
    int moved;

    if (ptr->free != ptr->size) {
        while (ptr->buffer[count].next != ptr->size) {
            count = ptr->buffer[count].next;
        }

        moved = ptr->free;

        ptr->buffer[moved].value = value;
        ptr->buffer[moved].next = ptr->size;
        ptr->buffer[count].next = moved;
        ptr->free = ptr->buffer[moved].next;

        return TRUE; 
    }

    return FALSE;
}