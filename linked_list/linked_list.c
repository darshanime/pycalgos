#include <stdio.h>


struct node{
  int value;
  struct node* next;
};


typedef struct {
  struct node* root;
} ll;

void add_to_ll(int value, ll* linked_list) {
  struct node new_node = {value, linked_list->root};
  linked_list->root = &new_node;
}

void print_ll(ll* ll2) {
  printf("%p", ll2);
  struct node* temp = ll2->root;
  while (temp->next != NULL) {
    printf("%d ", temp->value);
    temp = temp->next;
  }
}


int main()
{
  printf("Creating a linked list...\n");
  struct node root_node = {1, NULL};
  ll my_linked_list = { &root_node };
  for (int i = 0; i < 10000; i++) {
    add_to_ll(i, &my_linked_list);
  }
  printf("my_linked_list root value %d\n", my_linked_list.root->value);
  return 0;
}
