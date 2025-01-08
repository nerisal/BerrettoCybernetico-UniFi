/*
Scrivere la funzione C che riceve in ingresso una lista sequenziale di valori interi e la partiziona con l’algoritmo
partition. Scrivere anche la complessità dell’algoritmo.
*/

#include <stdio.h>
#include <stdlib.h>

typedef unsigned short int boolean;
#define TRUE 1
#define FALSE 0

struct list {
    int head;
    int tail;
    int size;
    int *buffer;
};

void swap(struct list *ptr, int n1, int n2) {
    int tmp;
    tmp = ptr->buffer[n1];
    ptr->buffer[n1] = ptr->buffer[n2];
    ptr->buffer[n2] = tmp;
}

int partition_sequential(struct list *ptr, int N) {
    int l = ptr->head;
    int r = ptr->tail;
    int pivot = ptr->buffer[ptr->head];

    while (l != r) {
        do {
            r = (r - 1) % ptr->size;
        } while (ptr->buffer[r] > pivot && l != r);
        if (r != l) {
            do {
                l = (l + 1) % ptr->size;
            } while (ptr->buffer[l] <= pivot && l != r);
            swap(ptr, l, r);
        }
    }
    swap(ptr, l, ptr->head);

    return (l);
}
