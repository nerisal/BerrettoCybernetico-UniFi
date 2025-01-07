/*
Scrivere la funzione C che riceve in ingresso una lista sequenziale di valori float ed una variabile target di tipo
float. La funzione cerca il primo elemento della lista uguale a target e rimuove l’elemento successivo se
esiste. La funzione restituisce TRUE nel caso in cui sia rimosso un elemento dalla lista, FALSE in caso contrario.
[Punteggi: definizioni 3pt, parametri e valori di ritorno 2pt, logica 7pt, funzione isequal 3pt]

*/

#include <stdio.h>
#include <stdlib.h>

typedef unsigned short int boolean;
#define TRUE 1
#define FALSE 0

struct list {
    int size;
    int head;
    int tail;
    float *buffer;
};

boolean find_and_remove_next(struct list *ptr, float target) {
    boolean found = FALSE;

    for (int count = ptr->head; count != ptr->tail && found != TRUE; count = (count + 1) % ptr->size) {
        if (ptr->buffer[count] == target) {
            for (int moved = (count + 1) % ptr->size; moved != ptr->tail; moved = (moved + 1) % ptr->size) {
                ptr->buffer[moved] = ptr->buffer[(moved + 1) % ptr->size];
            }

            ptr->tail = (ptr->tail - 1) % ptr->size;
            found = TRUE;
        }
    }

    return found;
}
