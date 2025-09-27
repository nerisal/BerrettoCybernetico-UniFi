/*
Scrivere la funzione C che riceve in ingresso una lista sequenziale di valori interi. Se N è il numero di elementi
presenti nella lista, supporre che i primi N1 elementi della lista siano ordinati tra loro in senso crescente e allo
stesso modo siano ordinati tra loro in senso crescente i rimanenti N-N1 elementi. La funzione deve allocare e
restituire un array di N elementi con ordinamento globale dei valori degli elementi della lista; deve inoltre
restituire il numero di elementi dell’array.
*/

#include <stdio.h>
#include <stdlib.h>

typedef unsigned short int boolean;
#define TRUE 1
#define FALSE 0

struct list {
    int size;
    int head;
    int tail;
    int *buffer;
};

void init(struct list *ptr, int size) {
    ptr->buffer = (int *)malloc(sizeof(int) * size);
    ptr->head = 0;
    ptr->tail = 0;
    ptr->size = size;
}

void visit(struct list *ptr) {
    printf("\nLista: ");
    for (int count = ptr->head; count != ptr->tail; count = (count + 1) % ptr->size)
        printf("%d ", ptr->buffer[count]);
}

boolean pre_insert(struct list *ptr, int value) {
    if (ptr->head != (ptr->tail + 1) % ptr->size) { // not full
        // printf("Valore inserto: %d\n", value);
        ptr->head = (ptr->head - 1 + ptr->size) % ptr->size;
        ptr->buffer[ptr->head] = value;
        return TRUE;
    } else
        return FALSE;
}

boolean merge(struct list *ptr, int N1, int *length, int *V) {
    *length = 0;
    int count = ptr->head;
    N1 = (N1 + ptr->head) % ptr->size;

    // Per prima cosa conto la dimensione dell'array che devo creare.
    while (count != ptr->tail) {
        count = (count + 1) % ptr->size;
        (*length)++;
    }

    V = (int *)malloc(sizeof(int) * *length);
    if (V == NULL) {
        return FALSE;
    }

    int i;
    int j;
    int k = 0;

    for (i = ptr->head, j = N1; i != N1 && j != count; i = (i + 1) % ptr->size, j = (j + 1) % ptr->size, k = k + 2) {
        if (ptr->buffer[i] > ptr->buffer[j]) {
            V[k] = ptr->buffer[j];
            V[k + 1] = ptr->buffer[i];
        } else {
            V[k] = ptr->buffer[i];
            V[k + 1] = ptr->buffer[j];
        }
    }

    while (i != N1) {
        V[k] = ptr->buffer[i];
        i = (i + 1) % ptr->size;
    }

    while (j != count) {
        V[k] = ptr->buffer[j];
        j = (j + 1) % ptr->size;
    }

    for (int k = 0; k < *length; k++) {
        printf(" %d ", V[k]);
    }

    return TRUE;
}

int main() {
    struct list a;
    int size = 10;
    int rimosso;
    int *V;

    init(&a, size);

    pre_insert(&a, 7);
    pre_insert(&a, 6);
    pre_insert(&a, 4);
    pre_insert(&a, 3);

    pre_insert(&a, 5);
    pre_insert(&a, 2);
    pre_insert(&a, 1);

    merge(&a, 3, &rimosso, V);

    visit(&a);
    printf("\n");

    return 0; 
}