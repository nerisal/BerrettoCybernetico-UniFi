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

int main()
{
    struct list a;
    int size = 10;

    init(&a, size);

    pre_insert(&a, 5);
    pre_insert(&a, 4);
    pre_insert(&a, 3);
    pre_insert(&a, 2);
    pre_insert(&a, 1);

    visit(&a);

    search(&a, 6);
    search(&a, 2);

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