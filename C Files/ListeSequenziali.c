#include <stdio.h>
#include <stdlib.h>

typedef unsigned short int boolean;
#define TRUE 1;
#define FALSE 0;

struct list
{
    int *buffer;
    int head;
    int tail;
    int size;
};

void init(struct list *ptr, int size);
void visit(struct list *ptr);
boolean search(struct list *ptr, int target);
boolean pre_insert(struct list *ptr, int value);
boolean suf_insert(struct list *ptr, int value);
boolean pre_remove(struct list *ptr, int *value); // Qua inserisco un value perché voglio ottenere il valore che rimuovo
boolean suf_remove(struct list *ptr, int *value); // Nel valore value inserisco il valore che rimuovo
boolean ord_insert(struct list *ptr, int target);
boolean ord_remove(struct list *ptr, int target);

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
    ptr->buffer = (int *)malloc(sizeof(int) * size);
    ptr->head = 0;
    ptr->tail = 0;
    ptr->size = size;
}

void visit(struct list *ptr)
{
    printf("\nLista: ");
    for (int count = ptr->head; count != ptr->tail; count = (count + 1) % ptr->size)
        printf("%d ", ptr->buffer[count]);
}

boolean search(struct list *ptr, int target)
{
    for (int count = ptr->head; count != ptr->tail; count = (count + 1) % ptr->size)
    {
        if (ptr->buffer[count] == target)
        {
            printf("Trovato! %d", ptr->buffer[count]);
            return TRUE;
        }
    }
    return FALSE;
}

boolean pre_insert(struct list *ptr, int value)
{
    if (ptr->head != (ptr->tail + 1) % ptr->size)
    { // not full
        printf("Valore inserto: %d\n", value);
        ptr->head = (ptr->head - 1 + ptr->size) % ptr->size;
        ptr->buffer[ptr->head] = value;
        return TRUE;
    }
    else
        return FALSE;
}

boolean suf_insert(struct list *ptr, int value)
{
    // Verifico che la lista non sia piena
    if (ptr->head != (ptr->tail + 1) % ptr->size)
    {
        ptr->buffer[ptr->tail] = value;
        ptr->tail = (ptr->tail + 1 + ptr->size) % ptr->size;

        return TRUE;
    }

    return FALSE;
}

boolean pre_remove(struct list *ptr, int *value)
{
    if (ptr->head != ptr->tail)
    {
        *value = ptr->buffer[ptr->head];
        ptr->head = (ptr->head + 1) % ptr->size;

        return TRUE;
    }
    return FALSE;
}

boolean suf_remove(struct list *ptr, int *value)
{
    if (ptr->head != ptr->tail)
    {
        *value = ptr->buffer[(ptr->tail - 1) % ptr->size];
        ptr->tail = (ptr->tail - 1) % ptr->size;
        return TRUE;
    }
    return FALSE;
}

boolean ord_insert(struct list *ptr, int target)
{
    // Devo verificare che la lista non sia piena
    if (ptr->head != (ptr->tail + 1) % ptr->size)
    {
        // So che la lista è ordinata e voglio inserire un valore quando incontro uno che è più grande
        int count = ptr->head;
        while (ptr->buffer[count] <= target && count != ptr->tail)
        {
            count = (count + 1) % ptr->size;
        }
        for (int position = ptr->tail; position != count; position = (position - 1) % ptr->size)
        {
            ptr->buffer[position] = ptr->buffer[(position - 1) % ptr->size];
        }
        ptr->buffer[count] = target;
        ptr->tail = (ptr->tail + 1) % ptr->size;
        return TRUE;
    }

    return FALSE;
}

// Il valore target indica il valore da rimuovere
boolean ord_remove(struct list *ptr, int target)
{
    int count = ptr->head;

    // Devo prima verificare che la lista non sia vuota
    if (ptr->head != ptr->tail)
    {
        // Devo fare un ciclo per trovare il valore che voglio rimuovere
        while (ptr->buffer[count] != target && count != ptr->tail)
            count = (count + 1) % ptr->size;

        // Sono arrivato in fondo e l'elemento che cerco non è presente nella lista
        if (ptr->buffer[count] != target)
        {
            printf("\nElemento non presente nella lista");
            return FALSE;
        }

        for (int position = count; position != ptr->tail; position = (position + 1) % ptr->size)
            ptr->buffer[position] = ptr->buffer[(position + 1) % ptr->size];
        ptr->tail = (ptr->tail - 1) % ptr->size;

        return TRUE;
    }
}