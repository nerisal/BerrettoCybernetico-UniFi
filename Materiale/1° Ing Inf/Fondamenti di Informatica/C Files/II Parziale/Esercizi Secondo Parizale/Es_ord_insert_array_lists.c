struct record {
    int value;
    int next;
};

struct list {
    struct record *buffer;
    int size;
    int first;
    int free;
};

void ord_insert(struct list *ptr, int target) {
    int moved, *position;

    if (ptr->free != ptr->size) {

        moved = ptr->free;
        ptr->free = ptr->buffer[ptr->free].next;
        position = &(ptr->first);

        while (*position != ptr->size && ptr->buffer[*position].value < target) {
            position = &(ptr->buffer[*position].next);
        }

        ptr->buffer[moved].value = target;
        ptr->buffer[moved].next = *position;
        *position = moved;
    }
}