#include <stdio.h>
#include <stdlib.h>

struct list {
    int data;
    struct list *next;
};

void pre_insert(struct list **head_ref, int new_data) {
    struct list *new_node =
        (struct list *)malloc(sizeof(struct list));

    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void printList(struct list *ptr) {
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}

void swap(struct list **first, struct list **second) {
    struct list *tmp = *first;
    *first = *second;
    *second = tmp;
}

void swapNodes(struct list **ptr, int K, int N) {
    struct list **first = ptr;
    struct list **second = ptr;

    for (int i = 1; i != K; i++) {
        first = &(*first)->next;
    }

    for (int i = 0; i < N; i++) {

        second = &(*first)->next;

        swap(first, second);
        swap(&(*first)->next, &(*second)->next);

        first = &((*first)->next);
    }
}

int main(void) {
    struct list *a = NULL;

    pre_insert(&a, 7);
    pre_insert(&a, 1);
    pre_insert(&a, 5);
    pre_insert(&a, 6);
    pre_insert(&a, 4);
    pre_insert(&a, 2);

    printf("\n Linked list before calling swapNodes() ");
    printList(a);

    swapNodes(&a, 3, 2);

    printf("\n Linked list after  calling swapNodes() ");
    printList(a);

    return 0;
}