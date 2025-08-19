// Modify Project 14 from Chapter 8 so that it stores the words in a two
// dimensional `char` array as it reads the sentence, with each row of the array
// storing a single word.
//
// Assume that the sentence contains no more than 30 words and no word is more
// than 20 characters long.
//
// Be sure to store a null character at the end of each word so that it can be
// treated as a string.

#include <stdio.h>
#include <string.h>

#define MAX_WRD_COUNT 30
#define WRD_LEN 21

int main(void) {
  char wrd[WRD_LEN], *pw = wrd;
  char sentence[MAX_WRD_COUNT][WRD_LEN];

  printf("enter a sentence: ");

  int ch, last_ch, i = 0;
  while ((ch = getchar()) != '\n') {
    if (ch == ' ') {
      *pw = '\0';
      strcpy(sentence[i++], wrd);
      memset(wrd, '\0', sizeof(wrd));
      pw = wrd;
      continue;
    }

    if (ch == '.' || ch == '!' || ch == '?') {
      *pw = '\0';
      strcpy(sentence[i++], wrd);
      memset(wrd, '\0', sizeof(wrd));
      last_ch = ch;
      continue;
    }

    *pw++ = ch;
  }

  printf("reversal of sentence:");
  int j = i - 1;
  while (j >= 0) {
    printf(" %s", sentence[j--]);
  }
  printf("%c\n", last_ch);

  return 0;
}
