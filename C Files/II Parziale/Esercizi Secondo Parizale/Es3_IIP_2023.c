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

boolean compare_and_swap(struct list **ptr, int *swaps) {
    struct list **first;
    struct list **second;
    struct list **tmp;

    first = ptr;
    **second = *(*ptr)->next->next;

    while (first != NULL && second != NULL) {
        if ((*first)->value > (*second)->value) {
            // Inverto il successivo
            tmp = (*first)->next;
            (*first)->next = (*second)->next;
            (*second)->next = tmp;
        }

        //??
    }

    first = second;
    second = (*second)->next->next;
}