// Modify the `inventory.c` program of Section 16.3 by adding two new
// operations:
//
// - Save the database in a specified file.
// - Load the database from a specified file.
//
// Use the codes `d` (dump) and `r` (restore), respectively, to represent these
// operations.

#include "readline.h"
#include <stdio.h>
#include <stdlib.h>
#define NAME_LEN 25
#define DB_BASE_FILENAME_LEN 80
#define MAX_PARTS 100

struct part {
  int number;
  char name[NAME_LEN + 1];
  int on_hand;
} inventory[MAX_PARTS];

int num_parts = 0;

int find_part(int number);
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

    // Skip to the end of the line.
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
      printf("Illegal code\n");
    }
  }
}

int find_part(int number) {
  int i;

  for (i = 0; i < num_parts; i++) {
    if (inventory[i].number == number) {
      return i;
    }
  }

  return -1;
}

void insert(void) {
  int part_number;

  if (num_parts == MAX_PARTS) {
    printf("Database is full; can't add more parts.\n");
    return;
  }

  printf("Enter part number: ");
  scanf("%d", &part_number);

  if (find_part(part_number) >= 0) {
    printf("Part already exists.\n");
    return;
  }

  inventory[num_parts].number = part_number;

  printf("Enter part name: ");
  read_line(inventory[num_parts].name, NAME_LEN);

  printf("Enter quantity on hand: ");
  scanf("%d", &inventory[num_parts].on_hand);

  num_parts++;
}

void search(void) {
  int i, number;

  printf("Enter part number: ");
  scanf("%d", &number);

  i = find_part(number);
  if (i >= 0) {
    printf("Part name: %s\n", inventory[i].name);
    printf("Quantity on hand: %d\n", inventory[i].on_hand);
  } else {
    printf("Part not found.\n");
  }
}

void update(void) {
  int i, number, change;

  printf("Enter part number: ");
  scanf("%d", &number);

  i = find_part(number);
  if (i >= 0) {
    printf("Enter change in quantity on hand: ");
    scanf("%d", &change);
    inventory[i].on_hand += change;
  } else {
    printf("Part not found.\n");
  }
}

void print(void) {
  int i;

  printf("Part Number    Part Name    Quantity on Hand\n");
  for (i = 0; i < num_parts; i++) {
    printf("%7d        %-25s%11d\n", inventory[i].number, inventory[i].name,
           inventory[i].on_hand);
  }
}

void dump(void) {
  printf("enter name of output file: ");

  char db_filename[DB_BASE_FILENAME_LEN];
  int i;
  for (i = 0; i < DB_BASE_FILENAME_LEN; i++) {
    int ch = getchar();
    if (ch == '\n') {
      break;
    }
    db_filename[i] = ch;
  }
  db_filename[i] = '\0';

  FILE *db = fopen(db_filename, "wb");
  if (db == NULL) {
    fprintf(
        stderr,
        "error: unable to save the inventory: could not create inv file %s\n",
        db_filename);
    exit(EXIT_FAILURE);
  }

  int nmemb = fwrite(inventory, sizeof(inventory[0]), num_parts, db);
  if (nmemb != num_parts) {
    fprintf(stderr,
            "error: unable to save the inventory: partial write occurred\n");
    fclose(db);
    remove(db_filename);
    exit(EXIT_FAILURE);
  }

  fclose(db);
}

void restore(void) {
  printf("enter name of input file: ");

  char db_filename[DB_BASE_FILENAME_LEN];
  int i;
  for (i = 0; i < DB_BASE_FILENAME_LEN; i++) {
    int ch = getchar();
    if (ch == '\n') {
      break;
    }
    db_filename[i] = ch;
  }
  db_filename[i] = '\0';

  FILE *db = fopen(db_filename, "rb");
  if (db == NULL) {
    fprintf(
        stderr,
        "error: unable to restore from inventory: could not read inv file %s\n",
        db_filename);
    exit(EXIT_FAILURE);
  }

  int read_parts = fread(inventory, sizeof(inventory[0]), MAX_PARTS, db);
  if (ferror(db)) {
    fprintf(stderr, "error: unable to restore from inventory\n");
    fclose(db);
    exit(EXIT_FAILURE);
  }

  num_parts = read_parts;
  fclose(db);
}
