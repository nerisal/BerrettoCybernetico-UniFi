/*
Scrivere la funzione C che riceve in ingresso una lista collegata con puntatori di valori interi ed opera nel modo
seguente:
• Gli elementi della lista sono scanditi a partire dalla testa: Se l’elemento corrente con valore i è seguito
da un elemento con valore j, j >= i+1, allora la lista è completata inserendo tra l’elemento con valore i e
l’elemento con valore j, tuti gli elementi con valori da i+1 a j-1;
• Se l’elemento corrente con valore i è seguito da un elemento con valore j, j <= i, allora l’elemento con
valore j è rimosso dalla lista. Gli elementi rimossi sono inseriti in un array V restituito tra i parametri
formali della funzione, insieme con il numero di valori rimossi dalla lista.
Scrivere anche l’equazione di costo e la complessità dell’algoritmo.
(Esempio: lista di ingresso {2,4,6,5,8}, lista di uscita {2,3,4,5,6,7,8}, array V = {5})
*/

#include <stdlib.h>
typedef unsigned short int boolean;
#define TRUE 1
#define FALSE 0

struct list {
    int value;
    struct list *next;
};

boolean complete_list(struct list **ptr, int *N_removed, int *V) {
    struct list *tmp;
    tmp = (struct list *)malloc(sizeof(struct list));

    while (NULL) {
    }
}