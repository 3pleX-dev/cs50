#include <stdio.h>
#include <stdlib.h>

/*
Node: {val: int, next: Node}
create
append
get_node
delete_node
print_nodes
free list
search
insert at index
*/

typedef struct Node {
  int val;
  struct Node *next;
} Node;

Node* list_create(const int val) {
  Node *ds = malloc(sizeof(Node));
  if (!ds) return NULL;

  ds->val = val;
  ds->next = NULL;

  return ds;
}

Node* list_append(Node *ds, int val) {
  Node *new_node = list_create(val);
  if (!new_node) return NULL;

  Node *cur = ds;
  while (cur->next != NULL) {
    cur = cur->next;
  }

  cur->next = new_node;

  return ds;
}

Node* list_insert(Node *ds, int val, int pos) {
  Node *new_node = list_create(val);
  if (!new_node) return NULL;

  if (pos == 0) {
    new_node->next = ds;
    return new_node;
  }

  // 1->2->3->4->5
  Node *cur = ds;
  for (int i = 0; i < pos - 1; i++) {
    if (!cur) return ds;
    cur = cur->next;
  }

  new_node->next = cur->next;
  cur->next = new_node;

  return ds;
}

Node* list_delete(Node *ds, int pos) {
  if (!ds) return NULL;

  if (pos == 0) {
    Node *new_head = ds->next;
    free(ds);
    return new_head;
  }

  Node *cur = ds;
  for (int i = 0; i < pos - 1; i++) {
    if (!cur || !cur->next) return ds;
    cur = cur->next;
  }

  Node *node_to_delete = cur->next;
  if (!node_to_delete) {
    return ds;
  }

  cur->next = node_to_delete->next;

  free(node_to_delete);

  return ds;
}

int list_getval(Node *ds, int pos) {
  if (!ds) return -1;

  Node *cur = ds;
  for (int i = 0; i < pos; i++) {
    if (!cur) return -1;
    cur = cur->next;
  }

  if (!cur) return -1;

  return cur->val;
}

int list_search(Node *ds, int val) {
  Node *cur = ds;
  int pos = 0;
  while (cur) {
    if (cur->val == val) return pos;
    cur = cur->next;
    pos++;
  }
  return -1;
}

void list_print(const Node *ds) {
  if (!ds) return;

  const Node *cur = ds;
  while (cur) {
    printf("val: %d\n", cur->val);
    cur = cur->next;
  }
}

void list_free(Node *ds) {
  Node *cur = ds;
  while (cur) {
    Node *tmp = cur;
    cur = cur->next;
    free(tmp);
  }
}

int main(void) {
  // 1. Create list with one element
  Node *list = list_create(10);
  printf("After creating list:\n");
  list_print(list);

  // 2. Append elements
  list_append(list, 20);
  list_append(list, 30);
  printf("\nAfter appending 20, 30:\n");
  list_print(list);

  // 3. Insert element at position 1
  list = list_insert(list, 15, 1);
  printf("\nAfter inserting 15 at position 1:\n");
  list_print(list);

  // 4. Insert element at head
  list = list_insert(list, 5, 0);
  printf("\nAfter inserting 5 at head:\n");
  list_print(list);

  // 5. Delete element at position 2
  list = list_delete(list, 2);
  printf("\nAfter deleting element at position 2:\n");
  list_print(list);

  // 6. Get value at position 3
  int val = list_getval(list, 3);
  printf("\nValue at position 3: %d\n", val);

  // 7. Search for a value
  int search_val = 30;
  int pos = list_search(list, search_val);
  if (pos != -1) {
      printf("Value %d found at position %d\n", search_val, pos);
  } else {
      printf("Value %d not found\n", search_val);
  }

  // 8. Free all nodes
  list_free(list);

    return 0;
}