// Write a program that sorts a series of words entered by the user:
//
// Example:
// Enter word: foo
// Enter word: bar
// Enter word: baz
// Enter word: quux
//
// In sorted order: bar baz foo quux
//
// Assume that each word is no more than 20 characters long.
// Stop reading when the user enters an empty word (i.e. presses Enter).
// Store each word in a dynamically allocated string, using an array of pointers
// to keep track of the strings. After all words have been read, sort the array
// (using any sorting technique), and then use a loop to print the words in
// sorted order.
//
// This solution is also done for the Project 6 by using `qsort` as the sorting
// technique.

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LEN 21
#define MAX_WORDS 60

int read_word(char *word, int len);
void add_word(char **words, int len, const char *word);
void sort_words(char **words, int len);
void print_words(char **words, int len);

int main(void) {
  char word[MAX_WORD_LEN];
  char *words[MAX_WORDS];
  int len = 0;

  for (;;) {
    printf("enter word: ");
    int bytes = read_word(word, MAX_WORD_LEN);
    if (bytes == 0 || len == MAX_WORDS) {
      sort_words(words, len);
      print_words(words, len);

      return 0;
    }

    add_word(words, len++, word);
  }

  return 0;
}

int read_word(char *word, int len) {
  int pos = 0;

  int ch;
  while ((ch = getchar()) != '\n') {
    if (isspace(ch)) {
      continue;
    }

    if (pos < len) {
      word[pos++] = ch;
    }
  }

  word[pos] = '\0';
  return pos;
}

void add_word(char **words, int len, const char *word) {
  int w_len = strlen(word);
  char *w = malloc(sizeof(char) * w_len + 1);
  if (w == NULL) {
    fprintf(stderr, "fatal: cannot malloc for word: out of memory");
    exit(EXIT_FAILURE);
  }

  strcpy(w, word);
  w[w_len] = '\0';

  words[len] = w;
}

int cmp(const void *w1, const void *w2) {
  // NOTE:
  // Normally, the pointers to compare are `const char**`,
  // but since the `cmp` signature expects `const void *`,
  // the casting is explicitly done as ptr to ptr and then
  // dereferenced to get the actual string values.
  return strcmp(*(const char **)w1, *(const char **)w2);
}

void sort_words(char **words, int len) {
  qsort(words, len, sizeof(char *), cmp);
}

void print_words(char **words, int len) {
  printf("\nin sorted order:");
  for (int i = 0; i < len; i++) {
    printf(" %s", words[i]);
  }

  printf("\n");
}
