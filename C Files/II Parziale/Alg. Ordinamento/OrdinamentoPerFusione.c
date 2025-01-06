#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef unsigned short int boolean;
#define TRUE 1;
#define FALSE 0;

void merge(int *V, int N, int N1, int *tmp);
void mergesort_f(int *V, int N);           // Funzione di facciata
void mergesort_r(int *V, int N, int *tmp); // Funzioen ricorsiva

int main() {
    int N = 10;
    int V[N];

    srand(time(0));

    for (int i = 0; i < N; i++) {
        V[i] = rand() % (100);
    }

    printf("\nL'array non ordinato è il seguente: ");
    for (int i = 0; i < N; i++) {
        printf(" %d ", V[i]);
    }

    mergesort_f(V, N);

    printf("\nL'array ordinato è il seguente: ");
    for (int i = 0; i < N; i++) {
        printf(" %d ", V[i]);
    }

    return 0;
}

// Per poter implementare il merge sort, occorre definire prima la funzione di merge ordinato
void merge(int *V, int N, int N1, int *tmp) { // Qui prendo due numeri, e poi li aggiungo all'array in ordine

    int l, r, count; // Creo le variabili che mi servono per le verifiche

    for (count = 0; count < N1; count++) // Copio in tmp, la parte sinistra dell'array
        tmp[count] = V[count];

    l = 0; // Imposto la variabile sinistra a zero
    r = 0; // Imposto la variabile destra a zero

    while (l < N1 && r < N - N1) { // Scorro la parte sinistra e la destra
        if (tmp[l] < V[N1 + r]) {  // Confronto ad uno ad uno gli elementi dell'array sinistro con quelli dell'array destro (considerando che sono ordinati)
            V[l + r] = tmp[l];
            l++;
        } else {
            V[l + r] = V[N1 + r];
            r++;
        }
    }

    // Inserisco gli elementi rimanenti
    while (l < N1) {
        V[l + r] = tmp[l];
        l++;
    }
}

// Creo la funzione di facciata del mergesort (questo mi evita di usare la funzione malloc di continuo)
void mergesort_f(int *V, int N) {
    int *tmp;
    tmp = (int *)malloc(sizeof(int) * N);
    mergesort_r(V, N, tmp);
    free(tmp);
}

void mergesort_r(int *V, int N, int *tmp) {
    if (N > 1) {
        mergesort_r(V, N / 2, tmp);                     // Qui passo la metà sinistra
        mergesort_r(&V[N / 2], N - N / 2, &tmp[N / 2]); // Qui passo la metà destra
        merge(V, N, N / 2, tmp);
    }
}