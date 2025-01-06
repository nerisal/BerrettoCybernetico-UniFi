/*
Scrivere la funzione che realizza l’inserimento in ordine in una lista sequenziale di valori float.
*/

typedef unsigned short int boolean;
#define TRUE 1
#define FALSE 0

struct list {
    int head;
    int tail;
    int size;
    int *buffer;
};

boolean ord_insert(struct list *ptr, int target) {
    int moved = ptr->head;

    if ((ptr->tail + 1) % ptr->size != ptr->head) {

        while (ptr->buffer[moved] < target && moved != ptr->tail) {
            moved = (moved + 1) % ptr->size;
        }

        for (int i = ptr->tail; i != moved; i = (i - 1) % ptr->size) {
            ptr->buffer[i] = ptr->buffer[(i - 1) % ptr->size];
        }

        ptr->buffer[moved] = target;
        return TRUE;
    }
    return FALSE;
}