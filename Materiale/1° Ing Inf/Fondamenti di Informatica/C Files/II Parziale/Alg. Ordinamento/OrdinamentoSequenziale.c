// Il problema dell'ordinamento sequenziale si riduce a quello del riconoscimento del massimo e del suo posizionamento in fondo alla lista
#include <stdio.h>
#include <stdlib.h>

typedef unsigned short int boolean;
#define TRUE 1;
#define FALSE 0;

void selection_sort(int *V, int N, int *perm);

int main() {
    int N = 10;
    int V[N];
    int perm[N];

    for (int i = 0; i < N; i++) {
        V[i] = rand() % (N + 1);
    }

    prtinf("\L'array non ordinato è il seguente: ");
    for (int i = 0; i < N; i++) {
        printf(" %d ", V[i]);
    }

    selection_sort(V, N, perm);

    prtinf("\L'array ordinato è il seguente: ");
    for (int i = 0; i < N; i++) {
        printf(" %d ", V[i]);
    }

    return 0;
}

void selection_sort(int *V, int N, int *perm) {
    int iter, count, count_of_max;
    for (count = 0; count < N; count++) {
        perm[count] = count;
        for (iter = 0; iter < N - 1; iter++) {
            for (count = 1; count_of_max = 0, count < N - iter; count++) {
                if (V[perm[count]] > V[perm[count_of_max]])
                    count_of_max = count;

                swap(perm, count_of_max, N - iter - 1);
            }
        }
    }
}
