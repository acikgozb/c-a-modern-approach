// Modify the `justify` program of Section 15.3 by rewriting the `line.c` file
// so that it stores the current line in a linked list. Each node in the list
// will store a single word. The `line` array will be replaced by a variable
// that points to the node containing the first word. This variable will store a
// null pointer whenever the line is empty.

#include "line.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 60

struct node {
  char *word;
  struct node *next;
};

struct node *line = NULL;
int line_len = 0;
int num_words = 0;

void clear_line(void) {
  struct node *p = line;
  while (p != NULL && p->next != NULL) {
    struct node *next = p->next;
    free(p);
    p = next;
  }

  line = NULL;
  line_len = 0;
  num_words = 0;
}

void add_word(const char *word) {
  struct node *n = malloc(sizeof(struct node));
  if (n == NULL) {
    fprintf(stderr, "fatal: failed to add node: out of memory\n");
    return;
  }

  char *w = malloc(sizeof(*word) + 2);
  if (w == NULL) {
    fprintf(stderr, "fatal: failed to add word: out of memory\n");
    return;
  }

  if (line == NULL) {
    strcpy(w, word);
  } else {
    w[0] = ' ';
    w[1] = '\0';
    strcat(w, word);
    line_len++;
  }

  n->word = w;
  n->next = NULL;

  if (line == NULL) {
    line = n;
  } else {
    struct node *prev;
    for (prev = line; prev->next != NULL; prev = prev->next)
      ;

    prev->next = n;
  }

  line_len += strlen(word);
  num_words++;
}

int space_remaining(void) { return MAX_LINE_LEN - line_len; }

void write_line(void) {
  int extra_spaces, spaces_to_insert, i, j;

  extra_spaces = MAX_LINE_LEN - line_len;

  struct node *p = line;
  while (p != NULL) {
    if (p->word[0] != ' ') {
      printf("%s", p->word);
    } else {
      spaces_to_insert = extra_spaces / num_words;
      for (j = 1; j <= spaces_to_insert + 1; j++) {
        putchar(' ');
      }
      extra_spaces -= spaces_to_insert;
      printf("%s", p->word + 1);
    }
    p = p->next;
    num_words--;
  }

  putchar('\n');
}

void flush_line(void) {
  if (line_len < 0) {
    return;
  }

  struct node *n = line;
  while (n != NULL) {
    printf("%s", n->word);
    n = n->next;
  }

  printf("\n");
}
