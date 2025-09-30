/*
Scrivere la funzione C che riceve in ingresso una lista collegata con array ed indici di valori float ed una
variabile target di tipo float. La funzione cerca gli elementi della lista uguali a target e li sposta in fondo alla
lista. La funzione restituisce TRUE nel caso in cui esista almeno un elemento uguale a target, FALSE in caso
contrario.
(Esempio: lista L = {3.2, 1.5, 6.7, 1.5, 2.0}, target = 1.5, lista di uscita L = {3.2, 6.7, 2.0, 1.5, 1.5})
*/

#include <stdalign.h>
#include <stdio.h>

typedef unsigned short int boolean;
#define TRUE 1
#define FALSE 0

struct record {
    int value;
    int next;
};

struct list {
    struct record *buffer;
    int first;
    int free;
    int size;
};

void init(struct list *ptr, int size) {
    ptr->buffer = (struct record *)malloc(sizeof(struct record) * size);
    ptr->size;
    ptr->free = 0;
    ptr->first = size;
    for (int count = 0; count < size; count++)
        ptr->buffer[count].next = count + 1;
}

boolean search_n_move(struct list *ptr, int target);

int main() {

    return 0;
}

boolean search_n_move(struct list *ptr, int target) {
    boolean found = FALSE;
    int last = ptr->first;
    int count = ptr->first;
    int tmp = count;
    int previous = ptr->first;
    int element_counter = 0;

    // Verifico che la lista non sia vuota
    if (ptr->first != ptr->size) {
        // Trovo l'ultimo valore
        while (ptr->buffer[last].next != ptr->size) {
            last = ptr->buffer[last].next;
            element_counter++;
        }

        for (int i = 0; i < element_counter; i++) {
            // Devo cambiare gli indici.
            if (ptr->buffer[count].value == target) {
                while (ptr->buffer[previous].next != count) {
                    previous = ptr->buffer[previous].next;
                }

                // Elimino il valore count e riallaccio gli indici di conseguenza
                ptr->buffer[previous].next = ptr->buffer[count].next;
                // Dico all'ultimo valore che ora count è quello che lo segue
                ptr->buffer[last].next = count;
                // Dicoe a count che è l'ultimo
                ptr->buffer[count].next = ptr->size;
                // Avanzo gli indici
                count = ptr->buffer[tmp].next;
                // Siccome ho effettuato uno scambio, non c'è bisogno di controllare anocora una volta l'ulimo valore quindi lo aumento di uno.
                i++;
                found = TRUE;
            }
        }
    }

    return found;
}