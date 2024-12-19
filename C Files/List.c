#include <stdlib.h>

typedef unsigned short int boolean;
#define TRUE 1
#define FALSE 0

/*
 * Le liste (per come sono usate in questo corso) non sono dei tipi di dato presente in maniera nativa all'interno del
 * linguaggio C. Dunque le definiamo per mezzo di dati strutturati.
 */

struct list {
  int *buffer; // Array che contiene effettivamente i valori all'interno della lista
  int head; // Valore che indica il primo elemento della lista
  int tail; // Valore che indica l'ultimo elemento della lista
  int size; // Dimensione della lista
};

void init(struct list *ptr, int size); // Prototipo della funzione di inizializzazione di una lista
boolean pre_insert(struct list *ptr, int value); // Prototipo della funzione di inserimento in testa
boolean post_insert(struct list *ptr, int value); // Prototipo della funzione di inserimento in coda
boolean pre_remove(struct list *ptr, int *value);

int main() {
  struct list a;

  init(&a, 10);

  return 0;
}


// Questa funzione serve per inizializzare una lista. Bisogna passargli anche un valore per la dimensione
void init(struct list *ptr, int size) {
  ptr->buffer = (int *) malloc(size * sizeof(int));
  ptr->size = size;
  ptr->head = 0;
  ptr->tail = 0;
}

// Si usa il tipo boolean per constatare se la funzione va a buon fine oppure no.
boolean pre_insert(struct list *ptr, int value) {
  // Questo verifica se la lista è piena TRUE = lista non piena
  if (ptr->head != (ptr->tail + 1) % ptr->size) {
    // Sposto il valore di head al valore precedente (utilizzando la matematica circolare)
    ptr->head = (ptr->head - 1 + %ptr->size) % ptr->size;
    // Inserisco il nuovo valore.
    ptr->buffer[ptr->head] = value;
    return TRUE;
  }
  // Ritorna falso se la lista è piena e quindi non è possibile inserire altri dati.
  return FALSE;
}

boolean post_insert(struct list *ptr, int value) {
  // Verifico che la lista non sia piena
  if (ptr->head != (ptr->tail + 1) % ptr->size) {
    // Prima inserisco in coda
    ptr->buffer[ptr->tail] = value;
    // Poi sposto l'ultimo elemento
    ptr->tail = (ptr->tail + 1) % ptr->size;
    return TRUE;
  }
  return FALSE;
}

boolean pre_remove(struct list *ptr, int *value) {
  // Lista non vuota
  if (ptr->head != ptr->tail) {
    *value = ptr->buffer[ptr->head];
    // Cambio la posizione di head
    ptr->head = (ptr->head + 1) % ptr->size;
    return FALSE;
  }
  return TRUE;
}


