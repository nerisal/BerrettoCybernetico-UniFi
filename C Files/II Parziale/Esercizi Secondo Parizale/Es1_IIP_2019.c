// Lista sequenziale di valori float -> inserimento in ordine
#include <stdio.h>
#include <stdlib.h>

typedef unsigned short int boolean;
#define TRUE 1
#define FALSE 0

struct list {
    int *buffer;
    int head;
    int tail;
    int size;
};

boolean ord_insert(struct list *ptr, int value) {
    int count = ptr->head;

    if (ptr->head != (ptr->tail + 1) % ptr->size) { // Not full
        while (ptr->buffer[count] <= value && count != ptr->tail) {
            count = (count + 1) % ptr->size;
        }

        for (int i = ptr->tail; i != count; i = (i - 1) % ptr->size) {
            ptr->buffer[i] = ptr->buffer[(i - 1) % ptr->size];
        }

        ptr->buffer[count] = value;
        ptr->tail = (ptr->tail + 1) % ptr->size;

        return TRUE;
    }

    return FALSE;
}