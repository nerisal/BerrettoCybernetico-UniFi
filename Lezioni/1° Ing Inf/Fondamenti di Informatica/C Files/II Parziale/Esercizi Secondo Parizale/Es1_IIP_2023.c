/*
Scrivere la funzione C che riceve in ingresso una lista collegata con array ed indici di valori float (struct
record{float value; int next;};) ed opera nel modo seguente:
• Confronta il campo valore di ogni elemento con il successore: se il campo value del successore ha
valore minore del campo value del predecessore allora il record viene rimosso dalla lista.
La funzione restituisce TRUE nel caso in cui sia stato rimosso almeno un elemento dalla lista, FALSE in caso
contrario.

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
    struct record *buffer;
    int first;
    int free;
    int size;
};

boolean compare_remove(struct list *ptr) {
    boolean found = FALSE;

    int count = ptr->first;
    int moved = ptr->first;
    int tmp;

    while (ptr->buffer[count].next != ptr->size) {
        tmp = ptr->buffer[count].next;

        if (ptr->buffer[ptr->buffer[count].next].value < ptr->buffer[count].value) {

            while (ptr->buffer[ptr->buffer[moved].next].value != ptr->buffer[count].value) {
                moved = ptr->buffer[moved].next;
            }

            ptr->buffer[ptr->free].next = ptr->free;
            ptr->free = count;
            ptr->buffer[moved].next = tmp;

            if (count == ptr->first) {
                ptr->first = tmp;
            }

            found = TRUE;
            moved = ptr->first;
        }
        count = tmp;
    }

    return found;
}
