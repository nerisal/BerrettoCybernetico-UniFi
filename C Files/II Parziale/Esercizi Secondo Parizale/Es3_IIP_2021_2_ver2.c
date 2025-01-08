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

boolean sort(struct list *ptr, int *length, int *V) {
    *length = 0;
    int count = ptr->head;

    // Per prima cosa conto la dimensione dell'array che devo creare.
    while (count != ptr->tail) {
        count = (count + 1) % ptr->size;
        (*length)++;
    }

    V = (int *)malloc(sizeof(int) * *length);
    if (V == NULL) {
        return FALSE;
    }

    for (int i = 0, count = ptr->head; i < *length; i++, count = (count + 1) % ptr->size) {
        V[i] = ptr->buffer[count];
    }

    int tmp;

    for (int i = 0; i < *length; i++) {
        for (int j = 0; j < *length; j++) {
            if (V[j] > V[j + 1]) {
                tmp = V[j];
                V[j] = V[j + 1];
                V[j + 1] = tmp;
            }
        }
    }
    printf("La lista ha dimensione: %d ed è così formata: ", *length);
    for (int k = 0; k < *length; k++) {
        printf("%d ", V[k]);
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

    sort(&a, &rimosso, V);

    visit(&a);
    printf("\n");

    return 0;
}