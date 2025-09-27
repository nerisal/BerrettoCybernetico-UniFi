/*
Scrivere la funzione C che riceve in ingresso una lista collegata con array ed indici di valori di tipo int e due
variabili x, e y di tipo int (con x diverso da y) e, se esistono, scambia l’elemento della lista con valore uguale
ad x con l’elemento della lista con valore uguale ad y, Lo scambio deve interessare solo i primi elementi con
valore uguale ad x e y (Nota: lo scambio deve essere eseguito scollegando i record e ricollegandoli nella giusta
posizione). La funzione restituisce TRUE nel caso in cui sia scambiata una coppia di elementi dalla lista, FALSE
in caso contrario.
*/

#include <stdio.h>
#include <stdlib.h>

typedef unsigned short int boolean;
#define TRUE 1
#define FALSE 0

struct list {
    int value;
    struct list *next;
};

void swap(struct list **first, struct list **second) {
    struct list *tmp = *first;
    *first = *second;
    *second = tmp;
}

boolean swap_x_y(struct list **ptr, int x, int y) {
    boolean found = FALSE;
    struct list **first = ptr;
    struct list **second = ptr;

    // Trovo x
    while ((*first)->value != x && first != NULL) {
        first = &(*first)->next;
    }
    if (first == NULL) {
        return FALSE;
    }

    while ((*second)->value != y && second != NULL) {
        second = &(*second)->next;
    }
    if (second == NULL) {
        return FALSE;
    }

    swap(first, second);                     // Scambio i due nodi
    swap(&(*first)->next, &(*second)->next); // Scambio i due nodi seguenti

    return TRUE;
}