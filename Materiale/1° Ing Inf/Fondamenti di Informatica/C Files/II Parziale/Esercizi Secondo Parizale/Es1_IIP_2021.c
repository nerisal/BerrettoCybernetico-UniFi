/*
Scrivere la funzione C che riceve in ingresso una lista collegata con puntatori di valori interi ed un array V di
interi di dimensione N ed opera nel modo seguente:
• Cancella dalla lista tutti gli elementi il cui valore è presente tra quelli dell’array (ipotizzare che il
numero di elementi della lista sia >> del numero di elementi dell’array e che nell’array non ci siano
ripetizioni);
• La funzione ritorna il valore TRUE se almeno un elemento della lista è stato cancellato, FALSE
altrimenti.
Scrivere anche l’equazione di costo e la complessità dell’algoritmo.
(Esempio: lista di ingresso {9,3,2,4,7,1,6,10,3,5,7,8}, array V = {7,3}, lista di uscita {9,2,4,1,6,10,5,8})
[Punteggi: definizioni 3pt, parametri e valori di ritorno 2pt, logica 7pt, costo e complessità 3pt]
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

boolean search_and_delete(struct list **ptr, int *V, int N) {
    boolean found = FALSE;

    struct list *tmp;
    struct list *save = *ptr;

    for (int i = 0; i < N; i++) {
        while ((*ptr)->value != V[i] && *ptr != NULL) {
            ptr = &((*ptr)->next);
        }

        if ((*ptr)->value == V[i]) {
            found = TRUE;
            tmp = *ptr;
            *ptr = (*ptr)->next;
            free(tmp);
        }

        ptr = save;
    }

    return found;
}