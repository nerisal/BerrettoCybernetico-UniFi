#include <stdio.h>
#include <stdlib.h>

typedef unsigned short int boolean;
#define TRUE 1
#define FALSE 0

struct ListItem {
    int value;
    struct ListItem *pNext;
};

void init(struct ListItem **ptr);
boolean pre_insert(struct ListItem **ptrptr, int value);
boolean suf_insert(struct ListItem **ptrptr, int value);
boolean ord_insert(struct ListItem **ptrptr, int value);
boolean pre_remove(struct ListItem **ptrptr, int *value);
boolean suf_remove(struct ListItem **ptrptr, int *value);
boolean ord_remove(struct ListItem **ptrptr, int target);
void visit(struct ListItem *ptr);
void visit_back(struct ListItem *ptr);
boolean search(struct ListItem *ptr, int target);
boolean clone(struct ListItem *src_ptr, struct ListItem **dst_ptr);
boolean clone2(struct ListItem *src_ptr, struct ListItem **dst_ptr);

int main() {
    struct ListItem *ptr;
    struct ListItem *dst_ptr;
    struct ListItem *dst2_ptr;
    int value;

    // init the ListItem
    init(&ptr);

    // test pre-insert
    pre_insert(&ptr, 5);
    pre_insert(&ptr, 3);
    pre_insert(&ptr, 1);

    visit(ptr);

    // test suf-insert
    suf_insert(&ptr, 6);
    suf_insert(&ptr, 8);

    visit(ptr);

    // test ord-insert
    ord_insert(&ptr, 0);
    ord_insert(&ptr, 7);

    visit(ptr);

    // test remove
    pre_remove(&ptr, &value);
    printf("\nValue %d has been removed from the List", value);
    suf_remove(&ptr, &value);
    printf("\nValue %d has been removed from the List", value);
    ord_remove(&ptr, 3);
    ord_remove(&ptr, 7);

    visit(ptr);

    // test search
    if (search(ptr, 5))
        printf("\nSearch termined with success!");
    else
        printf("\nSearch termined without success!");

    // test clone
    clone(ptr, &dst_ptr);
    visit(dst_ptr);
    // test clone2
    clone2(ptr, &dst2_ptr);
    visit(dst2_ptr);

    // test backward visit
    visit_back(dst2_ptr);

    printf("\n");
    // system("pause");
    return 0;
}

void init(struct ListItem **ptr) { *ptr = NULL; }

boolean pre_insert(struct ListItem **ptrptr, int value) {
    struct ListItem *tmp_ptr;
    tmp_ptr = (struct ListItem *)malloc(sizeof(struct ListItem));
    if (tmp_ptr != NULL) {
        tmp_ptr->value = value;
        tmp_ptr->pNext = *ptrptr;
        *ptrptr = tmp_ptr;
        return TRUE;
    } else
        return FALSE;
}

boolean suf_insert(struct ListItem **ptrptr, int value) {
    while (*ptrptr != NULL)
        ptrptr = &((*ptrptr)->pNext);
    if (pre_insert(ptrptr, value))
        return TRUE;
    else
        return FALSE;
}

boolean ord_insert(struct ListItem **ptrptr, int value) {
    while (*ptrptr != NULL && (*ptrptr)->value < value)
        ptrptr = &((*ptrptr)->pNext);
    if (pre_insert(ptrptr, value))
        return TRUE;
    else
        return FALSE;
}

boolean pre_remove(struct ListItem **ptrptr, int *value) {
    if (*ptrptr != NULL) {
        *value = (*ptrptr)->value;
        *ptrptr = (*ptrptr)->pNext;
        return TRUE;
    } else
        return FALSE;
}

boolean suf_remove(struct ListItem **ptrptr, int *value) {
    if (*ptrptr != NULL) { // not empty
        while ((*ptrptr)->pNext != NULL) {
            ptrptr = &((*ptrptr)->pNext);
        }
        pre_remove(ptrptr, value);
        return TRUE;
    } else
        return FALSE;
}

boolean ord_remove(struct ListItem **ptrptr, int target) {
    int value;
    boolean found = FALSE;

    if (*ptrptr != NULL) { // not empty
        while (*ptrptr != NULL && found == FALSE) {
            if ((*ptrptr)->value == target) {
                pre_remove(ptrptr, &value);
                printf("\nValue %d has been removed from the List", value);
                found = TRUE;
            } else
                ptrptr = &((*ptrptr)->pNext);
        }
    }
    return found;
}

void visit(struct ListItem *ptr) {
    printf("\nList: ");
    while (ptr != NULL) {
        printf("%d ", ptr->value);
        ptr = ptr->pNext;
    }
}

// backward visit of the ListItem. Elements are printed in reverse order
void visit_back(struct ListItem *ptr) {
    struct ListItem *tmp_ptr;

    init(&tmp_ptr);
    while (ptr != NULL) {
        pre_insert(&tmp_ptr, ptr->value);
        ptr = ptr->pNext;
    }
    visit(tmp_ptr);
}

boolean search(struct ListItem *ptr, int target) {
    boolean found = FALSE;

    while (ptr != NULL && found == FALSE) {
        if (ptr->value == target)
            found = TRUE;
        else
            ptr = ptr->pNext;
    }
    return found;
}

boolean clone(struct ListItem *src_ptr, struct ListItem **dst_ListItem) {
    boolean is_correct = TRUE;
    init(dst_ListItem);
    // insert all the elements of the source ListItem in the destination ListItem
    while (src_ptr != NULL && is_correct == TRUE) {
        is_correct = suf_insert(dst_ListItem, src_ptr->value);
        src_ptr = src_ptr->pNext;
    }
    return is_correct;
}

// clone with linear cost
boolean clone2(struct ListItem *src_ptr, struct ListItem **dst_ptr) {
    boolean is_correct = TRUE;
    init(dst_ptr);
    // insert all the elements of the source ListItem in the destination ListItem
    while (src_ptr != NULL && is_correct == TRUE) {
        is_correct = suf_insert(dst_ptr, src_ptr->value);
        // advance the pointer to the pNext filed of the last element of the
        // ListItem
        dst_ptr = &((*dst_ptr)->pNext);
        src_ptr = src_ptr->pNext;
    }
    return is_correct;
}