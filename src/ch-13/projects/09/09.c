// Modify Project 10 from Chapter 7 so that it includes the following function:
//
// int compute_vowel_count(const char *sentence);

#include <ctype.h>
#include <stdio.h>

#define SENTENCE_SIZE 80
#define ALPHABET_SIZE 26

int compute_vowel_count(const char *sentence);

int main(void) {
  printf("Enter a sentence: ");

  char s[SENTENCE_SIZE];
  int i;
  for (i = 0; i < SENTENCE_SIZE; i++) {
    int ch = getchar();
    if (ch == '\n') {
      break;
    }

    *(s + i) = tolower(ch);
  }
  *(s + i) = '\0';

  int count = compute_vowel_count(s);
  printf("your sentence contains %d vowels", count);
  return 0;
}

int compute_vowel_count(const char *sentence) {
  int values[ALPHABET_SIZE] = {1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0,
                               0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0};

  int count = 0;
  while (*sentence) {
    count += values[*sentence++ - 'a'];
  }

  return count;
}
