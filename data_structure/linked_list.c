#include <stdlib.h>
#include <stdio.h>

struct NodeInt {
  int data; 
  struct NodeInt *next;
};

struct LinkedList {
  struct NodeInt *first;
  struct NodeInt *last;

  void(*push_int)(struct LinkedList *self, int data);
  void(*print)(struct LinkedList *self);
};

void push_int(struct LinkedList *self, int value) {
  struct NodeInt *node = (struct NodeInt*) malloc(sizeof(struct NodeInt));
  node->data = value;
  node->next = NULL;

  if(self->first == NULL) {
    self->first = node;
    self->last = node;

    return;
  }

  struct NodeInt *last_node = self->last;
  last_node->next = node;

  self->last = node;
}

void print(struct LinkedList *linked_list) {
  struct NodeInt *curr_node = linked_list->first;

  for(int i = 0; curr_node != NULL; i++) {
    printf("Value of index %i: %i\n", i, curr_node->data);
    curr_node = curr_node->next;
  }
}

struct LinkedList* new_linked_list() {
  struct LinkedList *self = (struct LinkedList*) malloc(sizeof(struct LinkedList));
  self->first = NULL;
  self->last = NULL;

  self->push_int = &push_int;
  self->print = &print;

  return self;
}

int main() {
  struct LinkedList *linked_list = new_linked_list();

  int value = 0;

  do {
    printf("Type a value to push: \n");
    scanf("%i", &value);

    if(value > 0) {
      linked_list->push_int(linked_list, value);
    }

  } while(value > 0);

  linked_list->print(linked_list);
  
  system("PAUSE");
  return 0;
}