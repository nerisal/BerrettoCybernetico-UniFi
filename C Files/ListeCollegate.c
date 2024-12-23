// Liste collegate con array ed indici
// Ogni elemento si ricorda del suo successivo, gli elementi sono fisicamente disordinati
#include <stdlib.h>
#include <stdio.h>

typedef unsigned short int boolean;
#define TRUE 1;
#define FALSE 0;

struct record
{
    int value;
    int next;
};

struct list
{
    // Sto creando un array di tipo buffer. Dunque ogni elemento di questo array, è un dato strutturato formato da due valori interi
    struct record *buffer;
    int first;
    int size;
    int free;
};

void init(struct list *ptr, int size);
void visit(struct list *ptr);
boolean search(struct list *ptr, int target);
boolean pre_insert(struct list *ptr, int value);
boolean suf_insert(struct list *ptr, int value);
boolean pre_remove(struct list *ptr, int *value);
boolean suf_remove(struct list *ptr, int *value);
boolean ord_insert(struct list *ptr, int value);
boolean ord_remove(struct list *ptr, int value);

int main()
{
    struct list a;
    int size = 10;
    int rimosso;
    int *ptr_rimosso;

    ptr_rimosso = &rimosso;

    init(&a, size);

    pre_insert(&a, 2);
    pre_insert(&a, 1);
    visit(&a);
    printf("\n");

    printf("\nInserisco i valori 3, 5, 6 in coda");
    suf_insert(&a, 3);
    suf_insert(&a, 5);
    suf_insert(&a, 6);
    visit(&a);
    printf("\n");

    printf("\nRimuovo il primo valore");
    pre_remove(&a, ptr_rimosso);
    printf("\nÈ stato rimosso il valore: %d", *ptr_rimosso);
    visit(&a);
    printf("\n");

    printf("\nRimuovo l'ultimo valore");
    suf_remove(&a, ptr_rimosso);
    printf("\nÈ stato rimosso il valore: %d", *ptr_rimosso);
    visit(&a);
    printf("\n");

    printf("\nInserisco il valore 4 in maniera ordinata");
    ord_insert(&a, 4);
    visit(&a);
    printf("\n");

    printf("\nRimuovo il valore 6 in maniera ordinata");
    ord_remove(&a, 6);
    visit(&a);
    printf("\n");

    printf("\nRimuovo il valore 3 in maniera ordinata");
    ord_remove(&a, 3);
    visit(&a);
    printf("\n");

    search(&a, 6);

    return 0;
}

void init(struct list *ptr, int size)
{
    ptr->buffer = (struct record *)malloc(sizeof(struct record) * size);
    ptr->size = size;
    ptr->free = 0;
    ptr->first = size;
    for (int count = 0; count < size; count++)
        ptr->buffer[count].next = count + 1;
}

void visit(struct list *ptr)
{
    for (int position = ptr->first; position != ptr->size; position = ptr->buffer[position].next)
    {
        printf("\n buffer[%d]=%d", position, ptr->buffer[position].value);
    }
}

boolean search(struct list *ptr, int target)
{
    int count = ptr->first;
    while (count != ptr->size)
    {
        if (ptr->buffer[count].value == target)
        {
            printf("\nValore %d trovato", target);
            return TRUE;
        }

        count = ptr->buffer[count].next;
    }

    printf("\nValore %d non trovato", target);

    return FALSE;
}

boolean pre_insert(struct list *ptr, int value)
{
    int moved;
    // Verifico che la lista non sia piena
    // La lista è piena quando il primo elemento vuoto corrisponde con il primo elemento pieno
    if (ptr->free != ptr->size)
    {
        moved = ptr->free;
        ptr->free = ptr->buffer[moved].next;  // Aggiorno il valore del nuovo primo dei liberi
        ptr->buffer[moved].value = value;     // Assegno al primo valore libero il nuovo valore
        ptr->buffer[moved].next = ptr->first; // Dico che il prossimo del valore inserito è il primo della lista precente
        ptr->first = moved;                   // Dico che il primo valore della lista è il primo dei liberi precedente

        return TRUE;
    }

    return FALSE;
}

boolean suf_insert(struct list *ptr, int value)
{
    int moved;
    int count;

    if (ptr->free != ptr->size)
    {
        moved = ptr->free;
        count = ptr->first;

        while (ptr->buffer[count].next != ptr->size)
        {
            count = ptr->buffer[count].next; // Cerco la posizione dell'ultimo valore
        }

        ptr->buffer[moved].value = value;    // Assegno al primo valore libero il nuovo valore
        ptr->free = ptr->buffer[moved].next; // Aggiorno il primo valore libero
        ptr->buffer[count].next = moved;     // Aggiorno il seguente dell'ex-ultimo valore
        ptr->buffer[moved].next = ptr->size; // Imposto il seguente del nuovo ultimo valore

        return TRUE;
    }

    return FALSE;
}

boolean pre_remove(struct list *ptr, int *value)
{
    int moved = ptr->free;
    // Verifico che la lista non sia vuota
    if (ptr->first != ptr->size)
    {
        *value = ptr->buffer[ptr->first].value;

        ptr->free = ptr->first;
        ptr->buffer[moved].next = moved;
        ptr->first = ptr->buffer[ptr->first].next;

        return TRUE;
    }

    return FALSE;
}

boolean suf_remove(struct list *ptr, int *value)
{
    int moved, *position;

    if (ptr->first != ptr->size)
    { // not empty
        position = &(ptr->first);
        // move to the last element of the LinkedList
        while (ptr->buffer[*position].next != ptr->size)
            position = &(ptr->buffer[*position].next);
        // make available to the caller the value which is removed
        moved = *position;
        *value = ptr->buffer[*position].value;
        *position = ptr->buffer[moved].next;
        ptr->buffer[moved].next = ptr->free;
        ptr->free = moved;
        return TRUE;
    }
    else
        return FALSE;
}

boolean ord_insert(struct list *ptr, int value)
{
    int count;
    int moved;
    if (ptr->first != ptr->size)
    {
        count = ptr->first;

        while (ptr->buffer[count].value <= value && ptr->buffer[ptr->buffer[count].next].value < value)
        {
            count = ptr->buffer[count].next;
        }

        moved = ptr->free;

        ptr->buffer[moved].value = value;
        ptr->buffer[moved].next = ptr->buffer[count].next;
        ptr->buffer[count].next = moved;
        ptr->free = ptr->buffer[ptr->free].next;

        return TRUE;
    }

    return FALSE;
}

boolean ord_remove(struct list *ptr, int value)
{
    int count;

    if (ptr->first != ptr->size)
    {
        count = ptr->first;

        while (ptr->buffer[ptr->buffer[count].next].value != value)
        {
            if (count != ptr->size)
            {
                break;
            }
            count = ptr->buffer[count].next;
        }

        if (ptr->buffer[ptr->buffer[count].next].value != value)
        {
            printf("\nIl valore che si vuole rimuovere non è presente all'interno della lista");
            return FALSE;
        }

        ptr->buffer[count].next = ptr->buffer[ptr->buffer[count].next].next;
        ptr->free = ptr->buffer[count].next;
        ptr->buffer[ptr->free].next;

        return TRUE;
    }

    return FALSE;
}