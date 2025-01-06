/*
Scrivere la funzione C che riceve in ingresso una lista sequenziale di valori int ed opera nel modo seguente:
• Confronta il valore di ogni elemento con il successore: se il valore del successore è minore del
predecessore allora il record del successore viene rimosso dalla lista.
La funzione restituisce TRUE nel caso in cui sia stato rimosso almeno un elemento dalla lista, FALSE in caso
contrario.
Scrivere anche costo e complessità dell’algoritmo.
*/

typedef unsigned short int boolean;
#define TRUE 1
#define FALSE 0

struct list {
    int size;
    int head;
    int tail;
    int *buffer;
};

boolean compare_and_remove(struct list *ptr) {
    int count = ptr->head;
    boolean found = FALSE;

    // Verifico che la lista non sia vuota
    if (ptr->tail != ptr->head) {
        while (count != ptr->tail && ptr->buffer[(count + 1) % ptr->size] != ptr->tail) {
            if (ptr->buffer[count] > ptr->buffer[(count + 1) % ptr->size]) {
                for (int i = (count + 1) % ptr->size; i != ptr->tail; i = (i + 1) % ptr->size) {
                    ptr->buffer[i] = ptr->buffer[(i + 1) % ptr->size];
                }

                ptr->tail = (ptr->tail - 1) % ptr->size;
                found = TRUE;
            }

            count = (count + 1) % ptr->size;
        }
    }

    return found;
}

