/*
Scrivere la funzione C che riceve in ingresso una lista sequenziale L di valori interi ed un array V di interi di
dimensione N ed opera nel modo seguente:
• Rimuove dalla lista gli elementi con indice uguale a quelli contenuti nell’array. I valori dell’array non
presentano ripetizioni e possono essere positivi, nulli o negativi. L’elemento della lista con indice head
è considerato come elemento con indice 0. Gli indici sono riferiti alla posizione nella lista iniziale L;
• La funzione ritorna il numero di elementi rimossi (0 nel caso non sia rimosso alcun elemento).
Scrivere anche l’equazione di costo e la complessità dell’algoritmo.
(Esempio: lista L = {9,3,2,4,7,1,6,10,3}, array V = {12, 0, -3, 7}, lista di uscita L = {3,2,4,7,1,6,3})
*/

#include <stdio.h>
#include <stdlib.h>

typedef unsigned short int boolean;
#define TRUE 1
#define FALSE 0

// Definisco una lista sequenziale
struct list {
    int *buffer;
    int head;
    int tail;
    int size;
};

int remove(struct list *ptr, int *V, int N) { // N è la dimensione dell'array N
    int eliminations = 0;
    int tmp;

    // Per prima cosa ordino il vettore V in ordine descrescente
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - i - 1; j++) {
            if (V[j] < V[j + 1]) {
                tmp = V[j];
                V[j] = V[j + 1];
                V[j + 1] = tmp;
            }
        }
    }

    int count = ptr->head;

    // Ora che V è ordinato posso procedere con la rimozione e lo shift sulla lista
    for (int i = 0; i < N; i++) {
        if (0 <= V[i] && V[i] < ptr->size) {

            while (count != V[i]) {
                count = (count + 1) % ptr->size;
            }

            while (count != ptr->tail) {
                ptr->buffer[count] = ptr->buffer[(count + 1) % ptr->size];
                count = (count + 1) % ptr->size;
            }

            ptr->tail = (ptr->tail - 1) % ptr->size;
            eliminations++;
            count = ptr->head;
        }
    }

    return eliminations;
}