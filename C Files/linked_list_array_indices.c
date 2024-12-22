#include <stdlib.h>
#include <stdio.h>

typedef unsigned short int boolean;
#define TRUE 1
#define FALSE 0

struct ListItem {
    int value;
    int next;
};

struct LinkedList {
    struct ListItem * buffer;
    int size;
    int first;
    int free;
};

void init(struct LinkedList * ptr, int size);
boolean pre_insert(struct LinkedList * ptr, int value);
boolean suf_insert(struct LinkedList * ptr, int value);
boolean ord_insert(struct LinkedList * ptr, int value);
boolean pre_remove(struct LinkedList * ptr, int * value);
boolean suf_remove(struct LinkedList * ptr, int * value);
boolean ord_remove(struct LinkedList * ptr, int target);
void visit(struct LinkedList * ptr);
boolean search(struct LinkedList * ptr, int target);

int main() {
    struct LinkedList ptr;
    int size = 10;
    int value;

    init(&ptr,size);

    // test pre_insert
    pre_insert(&ptr, 7);
    pre_insert(&ptr, 5);
    pre_insert(&ptr, 3);
    pre_insert(&ptr, 1);

    visit(&ptr);

    // test suf_insert
    suf_insert(&ptr, 8);

    visit(&ptr);

    // test ord_insert
    ord_insert(&ptr, 4);
    ord_insert(&ptr, 0);
    ord_insert(&ptr, 9);
    visit(&ptr);

    // test search
    if ( search(&ptr,4) )
        printf("\nSearch termined with success!");
    else
        printf("\nSearch termined without success!");

    // test pre-remove
    pre_remove(&ptr,&value);
    printf("\nValue %d has been removed from the List",value);
    visit(&ptr);

    // test suf-remove
    suf_remove(&ptr,&value);
    printf("\nValue %d has been removed from the List",value);
    visit(&ptr);

    // test ord-remove
    ord_remove(&ptr,1);
    visit(&ptr);
    ord_remove(&ptr,8);
    visit(&ptr);
    ord_remove(&ptr,5);
    visit(&ptr);
    ord_remove(&ptr,7);
    visit(&ptr);
    ord_remove(&ptr,3);
    visit(&ptr);
    suf_remove(&ptr,&value);
    printf("\nValue %d has been removed from the List",value);
    visit(&ptr);
    suf_remove(&ptr,&value);
    printf("\nValue %d has been removed from the List",value);
    visit(&ptr);

    printf("\n");
    //system("pause");
    return 0;
}

void init(struct LinkedList * ptr, int size)
{
    int i;
    ptr->buffer = (struct ListItem *)malloc(sizeof(struct ListItem)*size);
    ptr->size = size;
    ptr->first = size;
    ptr->free = 0;
    for (i=0;i<size;i++)
        ptr->buffer[i].next = i+1;
}

void visit(struct LinkedList * ptr)
{
    int position;
    printf("\nList: ");
    position = ptr->first;
    while( position != ptr->size ) {
        printf("%d ",ptr->buffer[position].value);
        position = ptr->buffer[position].next;
    }
}

boolean pre_insert(struct LinkedList * ptr, int value)
{   /* se la lista libera non è vuota, ne sgancia il primo elemento,
    * lo aggancia in testa alla lista dei valori e ci memorizza il valore da inserire */
    int moved;

    if ( ptr->free != ptr->size ) { // not full
        printf("\ninsert values %d",value);
        //unhook first element
        moved = ptr->free;
        ptr->free = ptr->buffer[ptr->free].next;
        // insert new value
        ptr->buffer[moved].value = value;
        ptr->buffer[moved].next = ptr->first;
        ptr->first = moved;
        return TRUE;
    }
    return FALSE;
}

boolean suf_insert(struct LinkedList * ptr, int value)
{   /* Se la lista libera non è vuota, ne sgancia il primo elemento e lo aggancia
     * in coda alla lista dei valori, ci copia sopra il valore da inserire e attribuisce il
     * valore illegale al successore*/

    int moved, *position;

    if ( ptr->free != ptr->size ) { // not full
        printf("\ninsert values %d",value);
        //unhook first element from the empty list
        moved = ptr->free;
        ptr->free = ptr->buffer[ptr->free].next;
        position = &(ptr->first);
        //find the end of the list
        while ( *position != ptr->size )
            position = &(ptr->buffer[*position].next);
        // insert new value
        ptr->buffer[moved].value = value;
        ptr->buffer[moved].next = ptr->size;
        *position = moved;
        return TRUE;
    }
    return FALSE;
}

boolean ord_insert(struct LinkedList * ptr, int value)
{  /*assume che la lista sia ordinata, inserisce il nuovo elemento in ordine
    * E' analoga alla funzione di inserimento in coda, salvo l'aggiunta di una seconda condizione sul while
    * e uno swap nell' inserimento finale*/

    int moved, * position;

    if ( ptr->free != ptr->size ) { // list not full
        printf("\ninsert values %d",value);
        //unhook the first element from the empty list
        moved = ptr->free;
        ptr->free = ptr->buffer[ptr->free].next;
        position = &(ptr->first);
        // find where to insert the new value
        while ( *position != ptr->size && ptr->buffer[*position].value < value )
            position = &(ptr->buffer[*position].next);
        // insert in order
        ptr->buffer[moved].value = value;
        ptr->buffer[moved].next = *position;
        *position = moved;
        return TRUE;
    }
    return FALSE;
}

boolean pre_remove(struct LinkedList * ptr, int * value)
{
    int moved;

    if ( ptr->first != ptr->size ) { // not empty
        // make available to the caller the value which is removed
        moved = ptr->first;
        *value = ptr->buffer[ptr->first].value;
        ptr->first = ptr->buffer[ptr->first].next;

        ptr->buffer[moved].next = ptr->free;
        ptr->free = moved;
        return TRUE;
    }
    else
        return FALSE;
}

boolean suf_remove(struct LinkedList * ptr, int * value)
{
    int moved, *position;

    if ( ptr->first != ptr->size ) { // not empty
        position = &(ptr->first);
        // move to the last element of the LinkedList
        while ( ptr->buffer[*position].next != ptr->size )
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

// remove the first element of the LinkedList with value equal to the target
boolean ord_remove(struct LinkedList * ptr, int target)
{
    int moved, * position;
    boolean found = FALSE;

    if ( ptr->first != ptr->size ) { // not empty
        position = &ptr->first;
        // move to the last element of the LinkedList
        while ( ptr->buffer[*position].next != ptr->size && found == FALSE ) {
            if (ptr->buffer[*position].value == target)
                found = TRUE;
            else
                position = &(ptr->buffer[*position].next);
        }
        if ( found == TRUE ) {
            moved = *position;
            *position = ptr->buffer[moved].next;
            ptr->buffer[moved].next = ptr->free;
            ptr->free = moved;
            printf("\nValue %d has been removed from the List", target);
        }
    }
    return found;
}

boolean search(struct LinkedList * ptr, int target)
{
    boolean found = FALSE;
    int position;

    position = ptr->first;
    while ( position != ptr->size && found == FALSE ) {
        if ( ptr->buffer[position].value == target )
            found = TRUE;
        else
            position = ptr->buffer[position].next;
    }
    return found;
}