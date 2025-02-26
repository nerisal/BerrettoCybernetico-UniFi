/*
Scrivere la funzione C che riceve in ingresso una lista collegata con puntatori di valori interi, un intero K ed un
intero N ed opera nel modo seguente:
• Inverte l’ordine degli N elementi della lista successivi a quello con indice K (il primo elemento della lista
ha indice 1) ponendoli prima dell’elemento con indice K;
• La funzione deve anche restituire tra i parametri formali l’indirizzo dell’elemento in posizione K.
(Esempio: lista di ingresso {2,4,6,5,1,7}, K=3, N=2 → lista di uscita {2,4,1,5,6,7}, gli elementi 5 ed 1 sono invertiti
di ordine e posti prima del 6. L’indirizzo restituito è quello dell’elemento 1)
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

void invert(struct list **ptr, int N, int K, struct list **pos) {
    int count, i;
    struct list *tmp, **pos_k;

    *pos = NULL;
    count = 1;
    while (*ptr != NULL && count < K) {
        count++;
        ptr = &((*ptr)->next);
    }
    if (count == K) {

        pos_k = ptr; // indirizzo elemento in posizione K
        for (i = 0; i < N; i++) {
            // scollega elemento succesivo
            tmp = (*ptr)->next;
            (*ptr)->next = tmp->next;
            // ricollega prima
            tmp->next = *pos_k;
            *pos_k = tmp;

            ptr = &((*ptr)->next);
        }
        *pos = *pos_k;
    }
}
