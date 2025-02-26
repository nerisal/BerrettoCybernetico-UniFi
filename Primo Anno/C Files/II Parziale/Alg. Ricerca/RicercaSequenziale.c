// Il problema della ricerca sequenziale si basa sullo scorrere tutto l'array finché non si trova l'elemento desiderato

#include <stdio.h>
#include <stdlib.h>

typedef unsigned short int boolean;
#define TRUE 1
#define FALSE 0

boolean sequential_search(float *V, int N, float target);

int main() {
    int N = 10;
    float V[N];

    for (int i = 0; i < N; i++) {
        V[i] = i;
    }

    if (sequential_search(V, N, 4) == TRUE) {
        printf("\nElemento trovato");
    } else {
        printf("\nElemento non trovato");
    }

    return 0;
}

boolean sequential_search(float *V, int N, float target) {
    boolean found = FALSE;
    int count = 0;

    while (count < N && found == FALSE) {
        if (V[count] == target) {
            found = TRUE;
        } else
            count++;
    }

    return found;
}