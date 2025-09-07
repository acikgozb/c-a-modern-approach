// Modify the `inventory2.c` program of Section 17.5 by adding the `d` (dump)
// and `r` (restore) options described in Project 8. Since the part structures
// aren't stored in an array, the `d` operation can't save them all by a single
// call of `fwrite`. Instead, it will need to visit each node in the linked
// list, writing the part number, part name, and quantity on hand to a file. As
// it reads parts from a file, the `r` operation will rebuild the list one node
// at a time.

#include "readline.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define NAME_LEN 25
#define DB_BASE_FILENAME_LEN 80

struct part {
  int number;
  char name[NAME_LEN + 1];
  int on_hand;
};

// NOTE: Since storing the next pointer is meaningless, the actual data is put
// as a separate field in the node.
struct node {
  struct part data;
  struct node *next;
};

struct node *inventory = NULL;

struct part *find_part(int number);
void insert(void);
void search(void);
void update(void);
void print(void);

void dump(void);
void restore(void);

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
    case 'p':
      print();
      break;
    case 'd':
      dump();
      break;
    case 'r':
      restore();
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
  struct node *n;

  for (n = inventory; n != NULL && number > n->data.number; n = n->next)
    ;

  if (n != NULL && number == n->data.number) {
    return &n->data;
  }

  return NULL;
}

void insert(void) {
  struct node *cur, *prev, *new_node;

  new_node = malloc(sizeof(struct node));
  if (new_node == NULL) {
    fprintf(stderr, "database is full, can't add more parts\n");
    return;
  }

  printf("Enter part number: ");
  scanf("%d", &new_node->data.number);

  for (cur = inventory, prev = NULL;
       cur != NULL && new_node->data.number > cur->data.number;
       prev = cur, cur = cur->next)
    ;

  if (cur != NULL && new_node->data.number == cur->data.number) {
    fprintf(stderr, "part already exists.\n");
    free(new_node);
    return;
  }

  printf("Enter part name: ");
  read_line(new_node->data.name, NAME_LEN);
  printf("Enter quantity on hand: ");
  scanf("%d", &new_node->data.on_hand);

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
  struct node *p;

  printf("Part Number    Part Name    Quantity on Hand\n");
  for (p = inventory; p != NULL; p = p->next) {
    printf("%7d      %-25s%11d\n", p->data.number, p->data.name,
           p->data.on_hand);
  }
}

void dump(void) {
  printf("enter name of output file: ");

  char db_filename[DB_BASE_FILENAME_LEN];
  int i = 0;
  for (;;) {
    int ch = getchar();
    if (ch == '\n') {
      break;
    }
    db_filename[i++] = ch;
  }
  db_filename[i] = '\0';

  FILE *db = fopen(db_filename, "wb");
  if (db == NULL) {
    fprintf(stderr, "error: could not create database file %s\n", db_filename);
    exit(EXIT_FAILURE);
  }

  struct node *cur = inventory;
  while (cur != NULL) {
    int num = fwrite(&cur->data, sizeof(struct part), 1, db);
    if (num == 0) {
      fprintf(stderr, "error: could not write inventory to database\n");
      fclose(db);
      remove(db_filename);
      // NOTE: Since the inventory is not freed in either exit case (success or
      // failure), it is not cleaned up in here as well. This is certainly not
      // ideal but since the program is small and there will be no access to the
      // inventory after this, letting OS do the cleanup is acceptable.
      exit(EXIT_FAILURE);
    }

    cur = cur->next;
  }
}

void restore(void) {
  printf("enter name of input file: ");

  char db_filename[DB_BASE_FILENAME_LEN];
  int i = 0;
  for (;;) {
    int ch = getchar();
    if (ch == '\n') {
      break;
    }
    db_filename[i++] = ch;
  }
  db_filename[i] = '\0';

  FILE *db = fopen(db_filename, "rb");
  if (db == NULL) {
    fprintf(stderr, "error: could not create database file %s\n", db_filename);
    exit(EXIT_FAILURE);
  }

  struct node *cur = NULL;
  while (1) {
    struct node *n = malloc(sizeof(struct node));
    if (n == NULL) {
      fprintf(stderr, "error: failed to import database: not enough memory\n");
      fclose(db);
      exit(EXIT_FAILURE);
    }

    int num = fread(&n->data, sizeof(struct part), 1, db);

    bool is_eof = feof(db);
    if (is_eof) {
      break;
    }
    if (num == 0 && !is_eof) {
      fprintf(stderr, "error: failed to import from database\n");
      free(n);
      fclose(db);
      exit(EXIT_FAILURE);
    }

    n->next = NULL;
    if (cur == NULL) {
      inventory = n;
    } else {
      cur->next = n;
    }
    cur = n;
  }

  fclose(db);
}
