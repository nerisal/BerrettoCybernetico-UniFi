#include <stdio.h>
#include <stdlib.h>

void swap(int *V, int n1, int n2);
void quicksort_r(int *V, int N);
int partition(int *V, int N);

int main(int argc, char *argv[]) {
    int N;
    int count;
    int *V;

    // lettura della lunghezza del vettore
    printf("inserisci dimensione del vettore ==> ");
    scanf("%d", &N);

    // allocazione del vettore da ordinare e del vettore delle permutazioni degli indici
    V = (int *)malloc(sizeof(int) * N);
    // lettura degli elementi del vettore
    for (count = 0; count < N; count++) {
        printf("inserisci elemento %d ==> ", count);
        scanf("%d", &V[count]);
    }

    // chiamata della funzione di ordinamento
    quicksort_r(V, N);

    // stampa vettore ordinato
    printf("\nvettore ordinato: ");
    for (count = 0; count < N; count++) {
        printf("%d ", V[count]);
    }
    printf("\n\n");

    system("PAUSE");
    return 0;
}

/*
  quicksort
*/
void quicksort_r(int *V, int N) {
    int q;

    if (N > 0) {
        q = partition(V, N);
        quicksort_r(V, q - 1);
        quicksort_r(&V[q], N - q);
    }
}

/*
  - Partiziona un vettore in due insiemi rispettivamente minori uguali e maggiori
  rispetto ad un elemento pivot. Assume il primo elemento come pivot.

  - Restituisce il numero q di valori in V che sono minori o uguali al pivot,
  incluso il pivot stesso. Muove il pivot in posizione q.

  - Mette nelle prime q posizioni tutti e soli i minoranti del pivot
*/

int partition(int *V, int N) {
    int l;
    int r;
    int pivot;

    pivot = V[0]; // Assegno il pivot al primo elemento dell'array
    l = 0;        // Assegno ad l che l'indice di sinistra il primo valore
    r = N;        // Assegno a r l'ultimo elemento dell'arrau
    while (l < r) {
        // Cicli annidiati
        do {
            r--;
        } while (V[r] > pivot && r > l);
        if (r != l) {
            do {
                l++;
            } while (V[l] <= pivot && l < r);
            swap(V, l, r);
        }
    }
    swap(V, l, 0);

    printf(" Lista dopo aver eseguito il partition: ");
    for (int i = 0; i < N; i++) {
        printf(" %d ", V[i]);
    }

    return (l + 1);
}

/* esegue lo swap tra due elementi di un vettore
 */
void swap(int *V, int n1, int n2) {
    int tmp;
    tmp = V[n1];
    V[n1] = V[n2];
    V[n2] = tmp;
}
