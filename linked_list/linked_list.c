#include <stdio.h>
#include<stdlib.h>

struct node{
  int value;
  struct node* next;
};


typedef struct {
  struct node* root;
} ll;


struct node* create_new_node() {
  return malloc(sizeof(struct node));
}

void add_to_ll(int value, ll* linked_list) {
  struct node* new_node = create_new_node();
  new_node->value = value;
  new_node->next = linked_list->root;
  linked_list->root = new_node;
}

void print_ll(ll* ll2) {
  struct node* temp = ll2->root;
  while (temp->next != NULL) {
    printf("%d\n", temp->value);
    temp = temp->next;
  }
}

struct node* search_ll(int value, ll* ll2) {
  struct node* temp = ll2->root;
  while (temp != NULL) {
    if (temp->value == value) {
      return temp;
    }
    temp = temp->next;
  }
  return NULL;
}

struct node* insert_in_ll(ll* ll2, int before, int after, int value) {
  struct node* temp = ll2->root;
  struct node* prev = NULL;
  while (temp != NULL) {
    if (temp->value == value) {
      struct node* prev_node = create_new_node();
      prev_node->value = before;
      prev_node->next = temp;
      prev->next = prev_node;

      struct node* next_node = create_new_node();
      next_node->value = after;
      next_node->next = temp->next;
      temp->next = next_node;
    }
    prev = temp;
    temp = temp->next;
  }
  return NULL;
}

int main()
{
  printf("Creating a linked list...\n");
  struct node root_node = {1, NULL};
  ll my_linked_list = { &root_node };
  for (int i = 0; i < 10; i++) {
    add_to_ll(i, &my_linked_list);
  }
  struct node* res_node = search_ll(4, &my_linked_list);
  insert_in_ll(&my_linked_list, 100, 200, 4);
  print_ll(&my_linked_list);
  printf("%p, %d\n", &res_node, res_node->value);
  return 0;
}
