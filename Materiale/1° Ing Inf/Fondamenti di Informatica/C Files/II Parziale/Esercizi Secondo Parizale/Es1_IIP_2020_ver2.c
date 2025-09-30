/*
Scrivere la funzione C che riceve in ingresso una lista collegata con array e indici di valori float ed una
variabile target di tipo float e rimuove dalla lista tutti gli elementi uguali a target. La funzione restituisce
TRUE nel caso in cui sia stato rimosso almeno un elemento dalla lista, FALSE in caso contrario.
*/

#include <stdio.h>
#include <stdlib.h>

typedef unsigned short int boolean;
#define TRUE 1
#define FALSE 0

struct record {
    float value;
    int next;
};

struct list {
    int first;
    int free;
    int size;
    struct record *buffer;
};

boolean find_and_remove(struct list *ptr, float target) {
    boolean found = FALSE;

    int count = ptr->first;
    int moved;

    while (count != ptr->size) {
        if (ptr->buffer[count].value == target) {
            // Devo eliminare dalla lista il valore moved
            moved = ptr->free;
            ptr->free = count;
            ptr->buffer[ptr->free].next = moved;

            moved = ptr->first;

            // Trovo il precedente di count
            while (ptr->buffer[moved].next != count) {
                moved = ptr->buffer[moved].next;
            }

            ptr->buffer[moved].next = ptr->buffer[count].next;

            found = TRUE;
        }

        count = ptr->buffer[count].next;
    }

    return found;
}