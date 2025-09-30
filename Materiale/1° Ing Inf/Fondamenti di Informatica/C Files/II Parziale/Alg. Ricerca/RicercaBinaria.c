// La ricerca binaria (bicotomica o ordinata) è simile a quella sequenziale ma si riduce di metà l'array ad ogni ciclo;

#include <stdio.h>
#include <stdlib.h>

typedef unsigned short int boolean;
#define TRUE 1
#define FALSE 0

boolean binary_search_r(float *V, int N, float target);
boolean binary_search(float *V, int N, float target);

int main() {
    int N = 10;
    float V[N];

    for (int i = 0; i < N; i++) {
        V[i] = i;
    }

    for (int i = -6; i < 11; i++) {

        if (binary_search_r(V, N, i) == TRUE) {
            printf("\nElemento %d trovato", i);
        } else {
            printf("\nElemento %d non trovato", i);
        }
    }

    return 0;
}

// Questa soluzione utilizza un approccio ricorsivo
boolean binary_search_r(float *V, int N, float target) {
    int length = N;

    if (length > 0) {
        if (V[length / 2] == target) {

            return TRUE;
        } else {
            if (V[length / 2] > target) {
                return binary_search(V, N / 2, target);
            } else {
                return binary_search(&(V[N / 2]), N / 2, target);
            }
        }
    }

    return FALSE;
}

boolean binary_search(float *V, int N, float target) {
    boolean found = FALSE;
    int lenght = N;
    int first = 0;
    while (lenght > 0 && found == FALSE) {
        if (V[first + lenght / 2] == target) {
            found = TRUE;
        } else {
            if (V[first + lenght / 2] > target) {
                lenght = lenght / 2;
            } else {
                first = first + lenght / 2 + 1;
                lenght = lenght - (lenght / 2) - 1;
            }
        }
    }

    return found;
}