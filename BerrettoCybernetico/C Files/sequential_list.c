//
// Created by stefano on 18/11/2016.
//
#include <stdlib.h>
#include <stdio.h>

typedef unsigned short int boolean;
#define TRUE 1
#define FALSE 0

struct list {
    int * buffer;
    int head;
    int tail;
    int size;
};

int init(struct list * ptr, int size);
void visit(struct list * ptr);
boolean pre_insert(struct list * ptr, int value);
boolean suf_insert(struct list * ptr, int value);
boolean ord_insert(struct list * ptr, int value);
boolean pre_remove(struct list * ptr, int *value);
boolean suf_remove(struct list * ptr, int *value);
boolean ord_remove(struct list * ptr, int target);
boolean search(struct list * ptr, int target);

int main() {
    struct list a;
    int size = 4;  // the siz eof the list is fixed
    int count;
    int value;

    // check that the module is an operation with sign
    int w = (4-8)%5;
    printf("\nw is %d",w);

    // initialize the list
    init(&a,size);

    // insert elements in an ordered way using ord_insert
    for(count=4;count>0;count--)
        ord_insert(&a,count);

    // visit the list
    visit(&a);

    // insert two more elements one at the head and the other at the tail
    if ( pre_insert(&a,0)==FALSE )
        printf("\nerror inserting %d",0);
    if ( suf_insert(&a,5)==FALSE )
        printf("\nerror inserting %d",5);

    // visit the list
    visit(&a);

    // remove one element from the head and one from the tail
    pre_remove(&a, &value);
    suf_remove(&a, &value);

    // visit the list
    visit(&a);

    // remove an intermediate elements
    ord_remove(&a,3);
    ord_remove(&a,6);

    // visit the list
    visit(&a);

    // search the list
    if ( search(&a,4) )
        printf("\nvalue found");
    else
        printf("\nvalue not found");

    printf("\n\n");
    system("pause");
    return 0;
}

int init(struct list * ptr, int size)
{
    ptr->buffer = (int *)malloc(sizeof(int)*size);
    if( ptr->buffer != NULL ) {
        ptr->head = 0;
        ptr->tail = 0;
        ptr->size = size;
        return 0;
    }
    else
        return 1;
}

boolean pre_insert(struct list * ptr, int value)
{
    if (ptr->head!=(ptr->tail+1)%ptr->size) {   // not full
        printf("\nInserted value: %d",value);
        ptr->head = (ptr->head-1+ptr->size)%ptr->size;
        ptr->buffer[ptr->head] = value;
        return TRUE;
    }
    else
        return FALSE;
}

boolean suf_insert(struct list * ptr, int value)
{
    if (ptr->head!=(ptr->tail+1)%ptr->size) {   // not full
        printf("\nInserted value: %d",value);
        ptr->buffer[ptr->tail] = value;
        ptr->tail = (ptr->tail+1)%ptr->size;
        return TRUE;
    }
    else
        return FALSE;
}

boolean pre_remove(struct list * ptr, int *value)
{
    if (ptr->head!=ptr->tail) {   // not empty
        *value = ptr->buffer[ptr->head];
        ptr->head = (ptr->head+1)%ptr->size;
        printf("\nRemoved value: %d",*value);
        return TRUE;
    }
    else
        return FALSE;
}

boolean suf_remove(struct list * ptr, int *value)
{
    if (ptr->head!=ptr->tail) {   // not empty
        ptr->tail = (ptr->tail-1+ptr->size)%ptr->size;
        *value = ptr->buffer[ptr->tail];
        printf("\nRemoved value: %d",*value);
        return TRUE;
    }
    else
        return FALSE;
}

boolean ord_insert(struct list * ptr, int value)
{
    int position, count, N;

    if (ptr->head!=(ptr->tail+1)%ptr->size) {   // not full
        printf("\nInserted value: %d",value);
        position = ptr->head;
        while ( position != ptr->tail && ptr->buffer[position] <= value )
            position = (position + 1)%ptr->size;
        // number of elements in the list
        N = (ptr->tail - ptr->head + ptr->size)%ptr->size;
        if( (position - ptr->head + ptr->size)%ptr->size > N/2 ) {
            // there are less elements to move from position to tail, so move from the tail
            printf("\nmove elements starting from the tail clockwise");
            // move the elements from position to tail-1 clockwise
            for (count = ptr->tail; count != position; count=(count-1+ptr->size)%ptr->size)
                ptr->buffer[count] = ptr->buffer[(count - 1 + ptr->size) % ptr->size];
            // insert the new value in position
            ptr->buffer[position] = value;
            // update the tail
            ptr->tail = (ptr->tail + 1) % ptr->size;
        }
        else {
            // there are less elements to move from head to position-1, so move from the head
            printf("\nmove elements starting from the head counterclockwise");
            // move the elements from head to position-1 counterclockwise
            for (count = ptr->head; count != position; count = (count + 1)%ptr->size)
                ptr->buffer[(count-1+ptr->size)%ptr->size] = ptr->buffer[count];
            // insert the new value in position-1
            ptr->buffer[(position-1+ptr->size)%ptr->size] = value;
            // update the head
            ptr->head = (ptr->head - 1 + ptr->size) % ptr->size;
        }
        return TRUE;
    }
    else
        return FALSE;
}

boolean ord_remove(struct list * ptr, int target)
{
    boolean found = FALSE;
    int position, count, N;

    if ( ptr->head != ptr->tail ) { // not empty
        position = ptr->head;
        // search the target - the list is supposed to be sorted in ascending order
        while ( position!=ptr->tail && found==FALSE && ptr->buffer[position]<=target ){
            if ( ptr->buffer[position] == target )
               found = TRUE;
            else
               position = (position+1)%ptr->size;
        }
        if ( found == TRUE ) {
           printf("\nRemoved value: %d",ptr->buffer[position]);
           // number of elements in the list
           N = (ptr->tail - ptr->head + ptr->size)%ptr->size;
           if ( (position - ptr->head + ptr->size)%ptr->size >= N/2 ) {
              // there are less elements to move from position to tail, so move from the tail
              printf(" -- move elements from position to tail-1 counterclockwise");
              // move the elements from position to tail-1 counterclockwise
              for ( count=position; count!=(ptr->tail-1+ptr->size)%ptr->size; count=(count+1)%ptr->size )
                  ptr->buffer[count] = ptr->buffer[(count+1)%ptr->size];
              ptr->tail = (ptr->tail-1+ptr->size)%ptr->size;
           }
           else {
              // there are less elements to move from head to position-1, so move from the head
              printf(" -- move elements from the head clockwise");
              // move the elements from position-1 to head clockwise
              for (count = position; count != ptr->head; count = (count-1+ptr->size)%ptr->size)
                  ptr->buffer[count] = ptr->buffer[(count-1+ptr->size)%ptr->size];
              // update the head
              ptr->head = (ptr->head + 1) % ptr->size;
           }
        }
    }
    return found;
}

void visit(struct list * ptr)
{
    int position;
    printf("\nLista: ");
    position = ptr->head;
    while ( position != ptr->tail) {
        printf("%d ",ptr->buffer[position]);
        position = (position+1)%ptr->size;
    }
}

boolean search(struct list * ptr, int target)
{
    int position;
    boolean found = FALSE;

    position = ptr->head;
    while ( position != ptr->tail && found==FALSE ) {
        if (ptr->buffer[position] == target)
            found = TRUE;
        else
            position = (position+1)%ptr->size;
    }
    return found;
}
