// Modify the `inventory2.c` program of Section 17.5 by adding an `e (erase)`
// command that allows the user to remove a part from the database.

#include "readline.h"
#include <stdio.h>
#include <stdlib.h>

#define NAME_LEN 25

struct part {
  int number;
  char name[NAME_LEN + 1];
  int on_hand;
  struct part *next;
};

struct part *inventory = NULL; // points to the first part.

struct part *find_part(int number);
void insert(void);
void search(void);
void update(void);
void print(void);
// SOLUTION (1):
// Declare the function associated with the command (erase) here.
void erase(void);

int main(void) {
  char code;

  for (;;) {
    printf("Enter operation code: ");
    scanf(" %c", &code);

    while (getchar() != '\n')
      ;

    switch (code) {
    case 'i':
      insert();
      break;
    case 's':
      search();
      break;
    case 'u':
      update();
      break;
    // SOLUTION (2):
    // Bind the key `e` to the `erase` function.
    case 'e':
      erase();
      break;
    case 'p':
      print();
      break;
    case 'q':
      return 0;
    default:
      printf("Illegal code.\n");
    }

    printf("\n");
  }

  return 0;
}

struct part *find_part(int number) {
  struct part *p;

  for (p = inventory; p != NULL && number > p->number; p = p->next)
    ;

  if (p != NULL && number == p->number) {
    return p;
  }

  return NULL;
}

void insert(void) {
  struct part *cur, *prev, *new_node;

  new_node = malloc(sizeof(struct part));
  if (new_node == NULL) {
    fprintf(stderr, "database is full, can't add more parts\n");
    return;
  }

  printf("Enter part number: ");
  scanf("%d", &new_node->number);

  for (cur = inventory, prev = NULL;
       cur != NULL && new_node->number > cur->number;
       prev = cur, cur = cur->next)
    ;

  if (cur != NULL && new_node->number == cur->number) {
    fprintf(stderr, "part already exists.\n");
    free(new_node);
    return;
  }

  printf("Enter part name: ");
  read_line(new_node->name, NAME_LEN);
  printf("Enter quantity on hand: ");
  scanf("%d", &new_node->on_hand);

  new_node->next = cur;
  if (prev == NULL) {
    inventory = new_node;
  } else {
    prev->next = new_node;
  }
}

void search(void) {
  int number;
  struct part *p;

  printf("Enter part number: ");
  scanf("%d", &number);

  p = find_part(number);
  if (p != NULL) {
    printf("Part name: %s\n", p->name);
    printf("Quantity on hand: %d", p->on_hand);
  } else {
    fprintf(stderr, "part not found\n");
  }
}

void update(void) {
  int number, change;
  struct part *p;

  printf("Enter part number: ");
  scanf("%d", &number);

  p = find_part(number);
  if (p != NULL) {
    printf("Enter change in quantity on hand: ");
    scanf("%d", &change);
    p->on_hand += change;
  } else {
    fprintf(stderr, "part not found\n");
  }
}

void print(void) {
  struct part *p;

  printf("Part Number    Part Name    Quantity on Hand\n");
  for (p = inventory; p != NULL; p = p->next) {
    printf("%7d      %-25s%11d\n", p->number, p->name, p->on_hand);
  }
}

// SOLUTION (3):
// Implement the erase function.
void erase(void) {
  printf("Enter part number: ");
  int num;
  scanf("%d", &num);

  struct part *p = find_part(num);
  if (p == NULL) {
    fprintf(stderr, "part not found\n");
    return;
  }

  struct part *prev;
  for (prev = inventory; prev->next != p && prev->next != NULL;
       prev = prev->next)
    ;

  // IMPORTANT: If previous node is equal to the node that
  // is to be erased, that means the list has only one element.
  // In this case, it is important to handle the `inventory` global
  // pointer since it will be a dangling pointer when `erase` removes
  // the element.
  //
  // In here, we set the pointer to NULL to indicate that this pointer
  // no longer points to anything.
  // Memory wise: p, prev, and inventory all point to the same memory.
  // Therefore, calling `free` with any one of them works.
  if (prev == p) {
    free(inventory);
    inventory = NULL;
  } else {
    prev->next = p->next;
    free(p);
  }
}
