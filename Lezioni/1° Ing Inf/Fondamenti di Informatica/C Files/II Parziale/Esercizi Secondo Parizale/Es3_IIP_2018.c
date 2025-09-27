#include <stdio.h>
#include <stdlib.h>

typedef unsigned short int boolean;
#define TRUE 1
#define FALSE 0

struct list {
    int value;
    int pos;
    struct list *next;
};

int *remove(struct list **ptr, int size) {
    int *V;
    int count = 0;
    *V = (int *)malloc(sizeof(int) * size);

    for (int i = 0; i < size; i++) {
        V[i] = 0;
    }

    int f0 = 0, f1 = 1, tmp;

    while (f0 + f1 < size) {

        while ((*ptr)->next->pos != f0 + f1 && (*ptr)->next != NULL) {
            *ptr = (*ptr)->next;
        }

        // Aggiungo l'elemento c
        for (int i = 0; i < size; i++) {
            tmp = V[i];
            V[i] = (*ptr)->next->value;
            V[i + 1] = tmp;
        }

        // Rimuovo l'elemento
        (*ptr)->next = (*ptr)->next->next;
        free((*ptr)->next);

        // Incremento secondo la serie di fibbonacci
        tmp = f1;
        if (f0 == 0)
            f0 = 1;
        f1 = f1 + f0;
        f0 = tmp;
    }

    return *V;
}