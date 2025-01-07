/*
Scrivere la funzione C che riceve in ingresso due liste L1 ed L2 collegate con puntatori di valori interi. Gli
elementi di ciascuna lista sono ordinati in senso crescente. La funzione deve unire la lista L2 con la lista L1 in
modo che la lista L1 abbia al termine un numero di elementi pari alla somma degli elementi originariamente
presenti in L1 ed L2 con ordinamento globale.
(Esempio: lista L1 = {2, 3, 7}, L2 = {1, 4, 5, 9}, lista di uscita L1 = {1, 2, 3, 4, 5, 7, 9})
*/

#include <stdio.h>
#include <stdlib.h>

typedef unsigned short int boolean;
#define TRUE 1
#define FALSE 0

// Lista collegata da puntatori
struct list {
    int value;
    struct list *next;
};

void swap(struct list **first, struct list **second) {
    struct list *tmp = *first;
    *first = *second;
    *second = tmp;
}

void merge(struct list **L1, struct list **L2) {
    // Per prima cosa sistemo l'head della lista
    struct list **tmp;

    if ((*L1)->value > (*L2)->next) {
        swap(*L1, *L2);
        swap(&(*L1)->next, &(*L2)->next);
    }

    tmp = (*L1)->next;
    (*L1)->next = L2;
    L1 = &(*L1)->next;

    while (tmp != NULL && L2 != NULL) {
        if ((*tmp)->value > (*L2)->value) {
            L1 = tmp;
            tmp = &(*L2)->next;
            (*L2)->next = tmp;
        } else {
            (*tmp)->next = (*L2)->next;
            (*L1)->next = tmp;
        }
    }

    // Aggiungere il codice per aggiungere gli eventuali elementi rimasti
}
