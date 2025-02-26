// Scrivere la funzione C che realizza l'inserimento in coda ad una lista collegata con array ed indici. Ipotizzare
// che i valori della lista siano interi.

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
    struct record *buffer;
    int free;
    int first;
    int size;
};

boolean suf_insert(struct list *ptr, int value)
{
    int moved;
    int count;

    // Verifico che la lista non sia piena
    if (ptr->buffer[ptr->free].next != ptr->size)
    {
        count = ptr->first; // Salvo queste due variabili
        moved = ptr->free;

        ptr->buffer[ptr->free].value = value; // Assegno al primo valore libero il nuovo valore
        ptr->free = ptr->buffer[moved].next;  // Dico che il nuovo primo valore libero è il seguente dell'ex-primo valore libero
        ptr->buffer[moved].next = ptr->size;  // Dico che il nuovo valore è l'ultimo

        while (ptr->buffer[count].next != ptr->size)
        {
            count = ptr->buffer[count].next; // Trovo il valore dell'ex-ultimo valore
        }

        ptr->buffer[count].next = moved; // Dico all'ex-ultimo valore che il nuovo ultimo valore è il suo seguente

        return TRUE;
    }

    return FALSE;
}