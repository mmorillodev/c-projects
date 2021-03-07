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

struct LinkedList* get_empty_list();
void push_int(struct LinkedList *linked_list, int value);
void print_list(struct LinkedList *linked_list);

int main() {
  struct LinkedList *linked_list = get_empty_list();

  char keep_going = '\0';
  int value = 0;

  do {
    printf("Type a value to push: \n");
    scanf("%i", &value);

    push_int(linked_list, value);

    printf("Do you wish to continue? Y/N\n");
    scanf(" %c", &keep_going);
  

  } while(keep_going == 'y' || keep_going == 'Y');

  print_list(linked_list);
  
  system("PAUSE");
  return 0;
}

struct LinkedList* get_empty_list() {
  struct LinkedList *linked_list = (struct LinkedList*) malloc(sizeof(struct LinkedList));
  linked_list->first = NULL;
  linked_list->last = NULL;

  return linked_list;
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