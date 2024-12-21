#include <stdio.h>
#include <stdlib.h>

typedef unsigned short int boolean;
#define TRUE 1;
#define FALSE 0;

struct list{
  int *buffer;
  int head;
  int tail;
  int size;
};

void init(struct list *ptr, int size);
void visit(struct list *ptr);
boolean pre_insert(struct list *ptr, int value);
boolean search(struct list *ptr, int target);

int main(){
  struct list a;
  int size = 10;

  init(&a, size);

  pre_insert(&a, 6);
  pre_insert(&a, 5);
  pre_insert(&a, 4);
  pre_insert(&a, 3);
  pre_insert(&a, 2);  
  pre_insert(&a, 1);

  visit(&a);

  search(&a ,6);

  return 0;
}

void init(struct list *ptr, int size){
  ptr->buffer = (int *)malloc(sizeof(int)*size);
  ptr->head = 0;
  ptr->tail = 0;
  ptr->size = size;
}

void visit(struct list *ptr){
  printf("\nLista: ");
  for(int count = ptr->head; count != ptr->tail; count = (count + 1)%ptr->size)
    printf("%d ", ptr->buffer[count]);
}

boolean search(struct list *ptr, int target){
  for(int count = ptr->head; count != ptr->tail; count = (count + 1)%ptr->size){
    if(ptr->buffer[count] == target){
      printf("Trovato! %d", ptr->buffer[count]);
      return TRUE;
    }
  }
  return FALSE;
}

boolean pre_insert(struct list * ptr, int value)
{
    if (ptr->head!=(ptr->tail+1)%ptr->size) {   // not full
        printf("Inserted value: %d\n",value);
        ptr->head = (ptr->head-1+ptr->size)%ptr->size;
        ptr->buffer[ptr->head] = value;
        return TRUE;
    }
    else
        return FALSE;
}

