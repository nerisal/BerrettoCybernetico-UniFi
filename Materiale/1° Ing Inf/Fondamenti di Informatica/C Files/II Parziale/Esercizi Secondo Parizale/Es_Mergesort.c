/*
Passi del merge:
- Dividere l'array in due
- Verificare ed unire
- Aggiungere gli elementi rimasti
*/

void merge(int *V, int N, int N1, int *tmp) {
    int l, r, count;

    for (count = 0; count < N1; count++) {
        tmp[count] = V[count];
    }

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

void mergesort_f(int *V, int N) {
    int *tmp;
    tmp = (int *)malloc(sizeof(int) * N);
    mergesort_r(V, N, tmp);
    free(tmp);
}

void mergesort_r(int *V, int N, int *tmp) {
    if (N > 1) {
        mergesort_r(V, N / 2, tmp); // qu
        mergesort_r(&V[N / 2], N - N / 2, &tmp[N / 2]);
        merge(V, N, N / 2, tmp);
    }
}