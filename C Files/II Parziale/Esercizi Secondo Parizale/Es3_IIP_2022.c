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



void merge(struct list **L1, struct list **L2) {
    struct list **L3 = NULL;

    while (*L1 != NULL && *L2 != NULL) {
        struct list *tmp_first;
        tmp_first = (struct list *)malloc(sizeof(struct list));
        struct list *tmp_second;
        tmp_second = (struct list *)malloc(sizeof(struct list));

        while (*L3 != NULL) {
            L3 = &((*L3)->next);
        }

        if ((*L1)->value > (*L2)->value) {
            tmp_first->value = (*L2)->value;
            tmp_second->value = (*L1)->value;

            tmp_first->next = tmp_second;
            *L3 = tmp_first;
        } else {
            tmp_first->value = (*L1)->value;
            tmp_second->value = (*L2)->value;

            tmp_first->next = tmp_second;
            *L3 = tmp_first;
        }

        L1 = &((*L1)->next);
        L2 = &((*L2)->next);
    }

    while (*L1 != NULL) {
        struct list *tmp;
        tmp = (struct list *)malloc(sizeof(struct list));

        while (*L3 != NULL) {
            L3 = &((*L3)->next);
        }

        tmp->value = (*L1)->value;
        tmp->next = NULL;
        *L3 = tmp;

        L1 = &((*L1)->next);
    }

    while (*L2 != NULL) {
        struct list *tmp;
        tmp = (struct list *)malloc(sizeof(struct list));

        while (*L3 != NULL) {
            L3 = &((*L3)->next);
        }

        tmp->value = (*L2)->value;
        tmp->next = NULL;
        *L3 = tmp;

        L2 = &((*L2)->next);
    }
}
