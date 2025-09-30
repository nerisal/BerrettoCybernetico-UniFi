/*
Scrivere la funzione che inserisce in ordine in una lista collegata con array ed indici di valori float.
*/

typedef unsigned short int boolean;

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

boolean ord_insert(struct list *ptr, int value) {
    boolean found = 0;
    int moved, *position;

    if (ptr->free != ptr->size) { // lista non piena
        moved = ptr->free;
        ptr->free = ptr->buffer[ptr->free].next;
        position = &(ptr->first);
        while (*position != ptr->size && ptr->buffer[*position].value < value)
            position = &(ptr->buffer[*position].next);
        // insert
        ptr->buffer[moved].value = value;
        ptr->buffer[moved].next = *position;
        *position = moved;
        return 1;
    }
    return 0;
}
