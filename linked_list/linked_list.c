#include <stdio.h>
#include<stdlib.h>

struct node{
  int value;
  struct node* next;
};


typedef struct {
  struct node* root;
} ll;

void add_to_ll(int value, ll* linked_list) {
  struct node *new_node = malloc(sizeof(new_node));
  new_node->value = value;
  new_node->next = linked_list->root;
  linked_list->root = new_node;
}

void print_ll(ll* ll2) {
  struct node* temp = ll2->root;
  while (temp->next != NULL) {
    printf("%d\n", temp->value);
    struct node* release = temp;
    temp = temp->next;
    free(release);
  }
}


int main()
{
  printf("Creating a linked list...\n");
  struct node root_node = {1, NULL};
  ll my_linked_list = { &root_node };
  for (int i = 0; i < 10; i++) {
    add_to_ll(i, &my_linked_list);
  }
  print_ll(&my_linked_list);
  return 0;
}
