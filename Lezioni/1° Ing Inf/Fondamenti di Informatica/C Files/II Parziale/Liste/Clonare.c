#include <stdlib.h>
typedef unsigned short int boolean;
#define TRUE 1
#define FALSE 0

struct list
{
    int value;
    struct list *next;
};

void init(struct list **ptrptr)
{
    ptrptr = NULL;
}

boolean preinsert(struct list **ptrptr, int value)
{
    struct list *tmp;
    tmp = (struct list *)malloc(sizeof(struct list));
    if(tmp != NULL)
    {
        tmp->value = value;
        tmp->next = *ptrptr;
        *ptrptr = tmp;
        return TRUE;
    }
    return FALSE;
}

boolean sufinsert(struct list **ptrptr, int value)
{
    while(*ptrptr != NULL)
        ptrptr = &(*ptrptr)->next;
    if(preinsert(ptrptr, value))
        return TRUE;
    return FALSE;
}

void clone(struct list *src, struct list **dst)
{
    init(dst);
    while(src != NULL)
    {
        sufinsert(dst, src->value);
        src = src->next;
    }
}

void clone_lowcost(struct list *src, struct list **dst)
{
    init(dst);
    while(src != NULL)
    {
        sufinsert(dst, src->value);
        dst = &((*dst)->next);    //costo lineare grazie a questa riga che avanza la cella dell'array destinazione per evitare di scorrere tutte le volte elementi inutili.
        src = src->next;
    }
}


