#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef unsigned short int boolean;
#define TRUE 1
#define FALSE 0

void inv_bubbleSort(int *V, int size) {
    int tmp;

    for (int j = 0; j < size; j++) {
        for (int i = size - j - 1; i > 0; i--) {
            if (V[i] > V[i - 1]) {
                tmp = V[i];
                V[i] = V[i - 1];
                V[i - 1] = tmp;
            }
        }
    }
}

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

    inv_bubbleSort(V, N);

    printf("\nL'array ordinato è il seguente: ");
    for (int i = 0; i < N; i++) {
        printf(" %d ", V[i]);
    }

    return 0;
}