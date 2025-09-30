/*
Scrivere la funzione C che riceve in ingresso due liste sequenziali L1 ed L2 di valori interi e verifica se L1 è
inclusa in L2 (per ipotesi L1 ha un numero di elementi minore di L2). La funzione restituisce TRUE nel caso in
cui l’inclusione sia verificata, FALSE in caso contrario. Scrivere anche la complessità dell’algoritmo.
(Nota: L2 include L1 se è possibile trovare in L2 un sottoinsieme di elementi contigui che coincidono in
numero e valore con quelli di L1)
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

boolean check_membership(struct list *L1, struct list *L2) {
    boolean found = FALSE;
    boolean partially_contained;

    for (int i = L2->head, j = L1->head; i < L2->tail; i = (i + 1) % L2->size) {
        if (found != TRUE) {
            if (L2->buffer[i] == L1->buffer[j]) {
                partially_contained = TRUE;
                j = (j + 1) % L1->size;
            } else {
                j = L1->head;
                partially_contained = FALSE;
            }

            if (j == L1->tail && partially_contained == TRUE) {
                found == TRUE;
            }
        }
    }

    return found;
}