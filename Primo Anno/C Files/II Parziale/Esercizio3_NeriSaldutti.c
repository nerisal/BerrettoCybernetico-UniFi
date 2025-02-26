/*
Scrivere la funzione C che riceve in ingresso una lista collegata con puntatori di valori interi ed opera nel modo
seguente:
• Gli elementi della lista sono scanditi a partire dalla testa: Se l’elemento corrente con valore V è seguito
da un elemento con valore W, allora la lista è completata inserendo tra l’elemento con valore V e
l’elemento con valore W un nuovo elemento con valore uguale al resto della divisione intera tra V e W
se il resto è diverso da 0;
• Se in resto della divisione intera tra V e W è invece 0, l’elemento con valore W è rimosso dalla lista. Gli
elementi rimossi sono inseriti in un array A restituito tra i parametri formali della funzione, insieme con
il numero N di valori rimossi dalla lista.
*/

#include <stdio.h>
#include <stdlib.h>

typedef unsigned short int boolean;
#define TRUE 1
#define FALSE 0

struct list {
    int value;
    struct list *next;
};

void init(struct list **ptr);
void visit(struct list **ptr);
boolean pre_insert(struct list **ptr, int value);
boolean suf_insert(struct list **ptr, int value);
boolean suf_remove(struct list **ptr);
boolean pre_remove(struct list **ptr);
boolean function_es3(struct list **ptr, int *V, int *count);

int main() {
    struct list *list;
    int count;
    int *V;

    int insert = 1;

    init(&list);

    printf("Crea una lista c collegata con puntatori: \nInserisci 0 per interrompere l'inserimento \n");

    while (insert != 0) {
        scanf("%d", &insert);

        if (insert != 0) {
            count++;
            suf_insert(&list, insert);
        }
    }

    V = (int *)malloc(sizeof(int) * count);
    if (V == NULL) {

        printf("Allocazione dell'array fallita");
        return 0;
    }

    printf("\n La lista che hai inserito e' la seguente: ");
    visit(&list);

    function_es3(&list, V, &count);

    printf("\n La lista dopo l'esecuzione della funzione e' la seguente: ");
    visit(&list);

    printf("\nElementi rimossi: %d L'array dei rimossi e' V[", count);
    for (int i = 0; i < count; i++) {
        printf("%d,", V[i]);
    }
    printf("]");

    return 0;
}

void init(struct list **ptr) {
    *ptr = NULL;
}

void visit(struct list **ptr) {
    while (*ptr != NULL) {
        int value = (*ptr)->value;
        printf("%d ", value);
        ptr = &((*ptr)->next); // Aggiorna il puntatore alla posizione successiva.
    }
}

boolean pre_insert(struct list **ptr, int value) {
    struct list *tmp;
    tmp = (struct list *)malloc(sizeof(struct list));
    if (tmp != NULL) {
        tmp->value = value;
        tmp->next = *ptr;
        *ptr = tmp;
        return TRUE;
    } else
        return FALSE;
}

boolean suf_insert(struct list **ptr, int value) {
    while (*ptr != NULL)
        ptr = &((*ptr)->next);
    if (pre_insert(ptr, value))
        return TRUE;
    else
        return FALSE;
}

boolean pre_remove(struct list **ptr) {
    struct list *tmp;

    if (*ptr != NULL) {
        tmp = *ptr;
        *ptr = (*ptr)->next;
        free(tmp);
        return TRUE;
    } else
        return FALSE;
}

boolean function_es3(struct list **ptr, int *V, int *count) {
    struct list **first = ptr;
    struct list **second = &((*ptr)->next);
    int rest;

    *count = 0;

    while (*second != NULL) {
        if ((*first)->value != (*second)->value) {

            rest = (*first)->value % (*second)->value;
            if (rest != 0) {
                if (!pre_insert(second, rest)) {
                    printf("Allocazione fallita!");
                    return FALSE;
                }
                second = &(*second)->next;
            } else {
                V[*count] = (*second)->value;
                (*count)++;

                pre_remove(second);
            }

            first = second;
            second = &(*second)->next;
        }
    }

    return TRUE;
}