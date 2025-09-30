/*
    Scrivere la funzione C che riceve in ingresso una lista collegata con array ed indici di valori float (struct
    record{float value; int next;};) ed opera nel modo seguente:
    • Confronta il campo valore di ogni elemento con il successore: se il campo value del successore ha
    valore minore del campo value del predecessore allora il record viene rimosso dalla lista.
    La funzione restituisce TRUE nel caso in cui sia stato rimosso almeno un elemento dalla lista, FALSE in caso
    contrario.
*/

typedef unsigned short int boolean;
#define TRUE 1
#define FALSE 0

struct record {
    float value;
    int next;
};

struct list {
    int size;
    int first;
    int free;
    struct record *buffer;
};

boolean compare_and_remove(struct list *ptr) {
    boolean found = FALSE;
    int moved;

    int predecessore = ptr->first;
    int successore = ptr->buffer[ptr->first].next;

    while (successore != ptr->size) {
        if (ptr->buffer[predecessore].value > ptr->buffer[successore].value) {
            moved = ptr->free;
            ptr->buffer[ptr->free].next = moved;
            ptr->free = successore;

            ptr->buffer[predecessore].next = ptr->buffer[successore].next;
            found = TRUE;
        } else {
            int tmp;
            tmp = successore;
            successore = ptr->buffer[successore].next;
            predecessore = tmp;
        }
    }

    return found;
}