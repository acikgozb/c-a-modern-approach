// Modify Project 16 from Chapter 8 so that it includes the following function:
//
// bool are_anagrams(const char *word1, const char *word2);
//
// The function returns true if the strings pointed to by `word1` and `word2`
// are anagrams.

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>

#define ALPHABET_SIZE 26
#define WRD_SIZE 81

bool are_anagrams(const char *word1, const char *word2);

int main(void) {
  char word1[WRD_SIZE], word2[WRD_SIZE], *p;

  printf("enter first word: ");
  int ch;
  p = word1;
  while ((ch = getchar()) != '\n' && p < word1 + WRD_SIZE) {
    *p++ = ch;
  }
  *p = '\0';

  printf("enter second word: ");
  p = word2;
  while ((ch = getchar()) != '\n' && p < word2 + WRD_SIZE) {
    *p++ = ch;
  }
  *p = '\0';

  if (are_anagrams(word1, word2)) {
    printf("the words are anagrams.");
  } else {
    printf("the words are not anagrams.");
  }

  return 0;
}

bool are_anagrams(const char *word1, const char *word2) {
  int letter_counts[ALPHABET_SIZE] = {0};

  while (*word1) {
    int idx = tolower(*word1) - 'a';
    letter_counts[idx]++;
    word1++;
  }

  while (*word2) {
    int idx = tolower(*word2) - 'a';
    letter_counts[idx]--;
    word2++;
  }

  bool are_anagrams = true;
  for (int i = 0; i < ALPHABET_SIZE; i++) {
    if (letter_counts[i] != 0) {
      are_anagrams = false;
    }
  }

  return are_anagrams;
}
