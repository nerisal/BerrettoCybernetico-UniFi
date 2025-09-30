// Tipi di liste

// Lista sequenziale (circolare)
struct list_sequential {
    int head;
    int tail;
    int size;
    int *buffer;
};

// Lista collegata con indici
struct record {
    int value;
    int next;
};

struct list_index {
    int first;
    int free;
    int size;
    struct record *buffer;
};

// Lista collegata con puntatore
struct list_pointer {
    int value;
    struct list_pointer *next;
};