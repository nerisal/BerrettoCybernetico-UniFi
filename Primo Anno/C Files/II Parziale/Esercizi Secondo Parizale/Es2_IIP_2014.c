/*
Scrivere la funzione C che realizza l'algoritmo di ricerca binaria in forma ricorsiva su un array di valori interi.
Scrivere anche l'equazione di costo dell'algoritmo
*/
#include <stdio.h>
#include <stdlib.h>

typedef unsigned short int boolean;
#define TRUE 1;
#define FALSE 0;

boolean binary_search(int *V, int N, int target) {
    if (N > 0) {
        if (V[N / 2] == target) {

            return TRUE;
        } else {
            if (V[N / 2] > target) {                              // Metà destra
                return binary_search(V, N / 2, target);           // In ogni caso devo dimezzare il raggio della ricerca
            } else {                                              // Metà sinistra
                return binary_search(&(V[N / 2]), N / 2, target); // Qui, oltre a dimezzare N, faccio partire l'array dalla metà.
            }
        }
    }

    return FALSE;
}