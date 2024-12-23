#include <stdio.h>
#include <stdlib.h>

typedef unsigned short int boolean;
#define TRUE 1;
#define FALSE 0;

struct list
{
    int value;
    struct list *next;
};

void init(struct list **ptr);
void visit(struct list *ptr);
boolean search(struct list *ptr, int target);
void pre_insert(struct list **ptr, int value);
void suf_insert(struct list **ptrptr, struct list *ptr, int value);

int main()
{
    struct list *a; // Qui sto creando un puntatore allo struct list che ho creato globalmente

    init(&a);

    pre_insert(&a, 3); // Qui sto passando l'indirizzo di un puntatore, ovvero un puntatore a puntatore
    pre_insert(&a, 2);
    pre_insert(&a, 1);
    visit(a); // Qui passo l'indirizzo

    suf_insert(&a, a, 4);

    search(a, 2);

    return 0;
}

void init(struct list **ptr)
{
    *ptr = NULL;
}

void visit(struct list *ptr)
{
    while (ptr != NULL)
    {
        printf("\nValue = %d", ptr->value);
        ptr = ptr->next;
    }
}

boolean search(struct list *ptr, int target)
{
    while (ptr != NULL)
    {
        if (ptr->value == target)
        {
            printf("\nIl valore %d è presente nella lista", target);
            return TRUE;
        }
        else
        {
            ptr = ptr->next;
        }
    }

    return FALSE;
}

void pre_insert(struct list **ptr, int value)
{
    struct list *tmp;

    tmp = (struct list *)malloc(sizeof(struct list));
    tmp->value = value;
    tmp->next = *ptr;
    *ptr = tmp;
}

void suf_insert(struct list **ptrptr, struct list *ptr, int value)
{
    struct list *tmp;
    int count;

    tmp = (struct list *)malloc(sizeof(struct list));
    tmp->value = value;
    tmp->next = NULL;

    while (*ptrptr != NULL)
    {
        count = ptr->next;
    }

    //???
}