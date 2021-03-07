#include <stdlib.h>
#include <stdio.h>

struct LinkedList {
  struct NodeInt *first;
  struct NodeInt *last;
};

struct NodeInt {
  int data; 
  struct NodeInt *next;
};

void push_int(struct LinkedList *linked_list, int value);
void print_list(struct LinkedList *linked_list);

int main() {
  struct LinkedList *linked_list = (struct LinkedList*) malloc(sizeof(struct LinkedList));
  char keep_going = '\0';
  int value = 0;

  // do {
  //   printf("Type a value to push: \n");
  //   scanf("%i", &value);

  //   push_int(linked_list, value);

  //   printf("Do you wish to continue? Y/N\n");
  //   scanf("%s", &keep_going);

  // } while(keep_going == 'y' | keep_going == 'Y');

  push_int(linked_list, 0);
  printf("first insertion\n");
  print_list(linked_list);
  printf("\n");

  push_int(linked_list, 1);
  printf("second insertion\n");
  print_list(linked_list);
  printf("\n");

  push_int(linked_list, 2);
  printf("third insertion\n");
  print_list(linked_list);
  printf("\n");
  
  return 0;
}

void push_int(struct LinkedList *linked_list, int value) {
  struct NodeInt *node = (struct NodeInt*) malloc(sizeof(struct NodeInt));
  node->data = value;
  node->next = NULL;

  if(linked_list->first == NULL) {
    linked_list->first = node;
    linked_list->last = node;

    return;
  }

  struct NodeInt *last_node = linked_list->last;
  last_node->next = node;

  linked_list->last = node;
}

void print_list(struct LinkedList *linked_list) {
  struct NodeInt *curr_node = linked_list->first;
  for(int i = 0; curr_node != NULL; i++) {
    printf("Value of index %i: %i\n", i, curr_node->data);
    curr_node = curr_node->next;
  }
}