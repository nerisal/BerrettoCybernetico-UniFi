/*
Scrivere la funzione C che riceve in ingresso una lista sequenziale di valori float ed una
variabile target di tipo float e rimuove dalla lista tutti gli elementi uguali a target. La funzione restituisce
TRUE nel caso in cui sia stato rimosso almeno un elemento dalla lista, FALSE in caso contrario.
*/

#include <stdio.h>
#include <stdlib.h>

typedef unsigned short int boolean;
#define TRUE 1
#define FALSE 0

struct list {
    int size;
    int head;
    int tail;
    float *buffer;
};

boolean search_and_remove(struct list *ptr, float target) {
    boolean found = FALSE;
    int count = ptr->head;

    while (count != ptr->tail) {
        if (ptr->buffer[count] == target) {
            for (int i = count; i != ptr->tail; i = (i + 1) % ptr->size) {
                ptr->buffer[count] = ptr->buffer[(count + 1) % ptr->size];
            }

            ptr->tail = (ptr->tail - 1) % ptr->size;
            found = TRUE;
        }

        count = (count + 1) % ptr->size;
    }

    return found;
}