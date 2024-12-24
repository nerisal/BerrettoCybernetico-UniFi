#include <stdio.h>
#include <stdlib.h>

typedef unsigned short int boolean;
#define TRUE 1;
#define FALSE 0;

struct list {
    int value;
    struct list *next;
};

void init(struct list **ptr); // Qui passo un puntatore a puntatore perché la lista nel main() è anch'essa un puntatore
void visit(struct list **ptr);
boolean search(struct list **ptr, int value);
boolean pre_insert(struct list **ptr, int value);
boolean suf_insert(struct list **ptr, int value);
boolean pre_remove(struct list **ptr, int *value);

int main() {
    struct list *a;
    init(&a);

    pre_insert(&a, 2);
    pre_insert(&a, 1);
    visit(&a);
    printf("\n");

    printf("\nInserisco i valori 3, 5, 6 in coda");
    suf_insert(&a, 3);
    suf_insert(&a, 5);
    suf_insert(&a, 6);
    visit(&a);
    printf("\n");

    search(&a, 1);

    return 0;
}

void init(struct list **ptr) {
    // La lista vuota è caratterizzata da ptr == NULL
    *ptr = NULL;
}

void visit(struct list **ptr) {

    printf("\nLista: ");
    while (*ptr != NULL) {
        int value = (*ptr)->value;
        printf("%d ", value);
        ptr = &((*ptr)->next); // Aggiorna il puntatore alla posizione successiva.
    }
}

boolean search(struct list **ptr, int value) {
    while (*ptr != NULL) {
        if ((*ptr)->value == value) {

            printf("\nL'elemento %d si trova al'interno della lista", value);
            return TRUE;
        }

        ptr = &((*ptr)->next);
    }

    printf("\nL'elemento %d non si trova all'interno della lista", value);
    return FALSE;
}

boolean pre_insert(struct list **ptr, int value) {
    struct list *tmp;
    tmp = (struct list *)malloc(sizeof(struct list));
    if (tmp != NULL) {
        tmp->value = value;
        tmp->next = *ptr;
        *ptr = tmp;

        return TRUE;
    }
    return FALSE;
}

boolean suf_insert(struct list **ptr, int value) {
    struct list *tmp;
    tmp = (struct list *)malloc(sizeof(struct list));

    if (tmp != NULL) {
        while (*ptr != NULL) // Trovo l'ultimo valore
        {
            ptr = &((*ptr)->next); // Se l'elemento in considerazione non è l'ultimo avanzo
        }

        // Effettuo lo scambio dei puntatori
        tmp->value = value;
        tmp->next = NULL;
        *ptr = tmp;

        return TRUE;
    }

    return FALSE;
}

boolean pre_remove(struct list **ptr, int *value) {
    if (*ptr != NULL) // Verifico che la lista non sia vuota
    {
    }

    return FALSE;
}