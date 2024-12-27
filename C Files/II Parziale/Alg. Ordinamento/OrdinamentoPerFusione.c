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

    int l, r, count;

    for (count = 0; count < N1; count++)
        tmp[count] = V[count];

    l = 0;
    r = 0;
    while (l < N1 && r < N - N1) {
        if (tmp[l] < V[N1 + r]) {
            V[l + r] = tmp[l];
            l++;
        } else {
            V[l + r] = V[N1 + r];
            r++;
        }
    }

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
        mergesort_r(V, N / 2, tmp);
        mergesort_r(&V[N / 2], N - N / 2, &tmp[N / 2]);
        merge(V, N, N / 2, tmp);
    }
}