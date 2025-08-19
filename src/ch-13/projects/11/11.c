// Modify Project 13 from Chapter 7 so that it includes the following function:
//
// double compute_average_word_length(const char *sentence);

#include <stdio.h>

#define SENTENCE_SIZE 81

double compute_average_word_length(const char *sentence);

int main(void) {
  printf("enter a sentence: ");

  char sentence[SENTENCE_SIZE], *p;
  for (p = sentence; p < sentence + SENTENCE_SIZE; p++) {
    int ch = getchar();
    if (ch == '\n') {
      break;
    }
    *p = ch;
  }
  *p = '\0';

  double length = compute_average_word_length(sentence);
  printf("average word length: %.1f", length);

  return 0;
}

double compute_average_word_length(const char *sentence) {
  int w_count = 0;
  int ch_count = 0;

  while (*sentence) {
    char ch = *sentence++;
    if (ch == ' ' || ch == '.') {
      w_count++;
    } else {
      ch_count++;
    }
  }

  return (double)ch_count / w_count;
}
