/*
Scrivere la funzione C che riceve in ingresso una lista collegata con puntatori di valori interi ed opera nel modo
seguente:
• Confronta coppie di elementi consecutivi con posizione dispari (il primo elemento della lista ha
posizione 1): se il valore degli elementi è fuori ordine (il primo è maggiore del secondo) inverte la
posizione degli elementi scollegandoli e ricollegandoli dalla lista;
• La funzione ritorna tra i parametri formali il numero di swap eseguiti;
(Esempio: lista di ingresso {2,4,6,5,1,7}, lista di uscita {2,4,1,5,6,7})
*/

#include <stdio.h>
#include <stdlib.h>

typedef unsigned short int boolean;
#define TRUE 1
#define FALSE 0

struct list {
    struct list *next;
    int value;
};

boolean pre_insert(struct list **ptr, int value) {
    struct list *tmp;
    tmp = (struct list *)malloc(sizeof(struct list));
    if (tmp != NULL) {
        tmp->value = value;
        tmp->next = *ptr;
        *ptr = tmp;

        return TRUE;
    }
    return FALSE;
}

void printList(struct list *ptr) {
    while (ptr != NULL) {
        printf("%d ", ptr->value);
        ptr = ptr->next;
    }
}

void swap(struct list **first, struct list **second) {
    struct list *tmp = *first;
    *first = *second;
    *second = tmp;
}

void compare_and_swap(struct list **ptr, int *swaps) {
    struct list **first = ptr;
    struct list **second = &((*ptr)->next->next);

    while (second != NULL) {
        if ((*first)->value > (*second)->value) {
            swap(first, second);
            swap(&(*first)->next, &(*second)->next);

            (*swaps)++;
        } else {

            first = second;
            second = &(*second)->next;
            second = &(*second)->next;
        }
    }
}

int main(void) {
    struct list *a = NULL;
    int swaps = 0;

    pre_insert(&a, 0);
    pre_insert(&a, 7);
    pre_insert(&a, 1);
    pre_insert(&a, 5);
    pre_insert(&a, 6);
    pre_insert(&a, 4);
    pre_insert(&a, 2); 

    printf("\n Linked list before calling swapNodes() ");
    printList(a);

    compare_and_swap(&a, &swaps);

    printf("\n Linked list after  calling swapNodes(). %d swaps were made ", swaps);
    printList(a);

    return 0;
}