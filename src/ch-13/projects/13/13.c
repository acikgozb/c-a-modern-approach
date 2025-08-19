// Modify Project 15 from Chapter 8 so that it includes the following function:
//
// void encrypt(char *message, int shift);
//
// The function expects `message` to point to a string containing the message to
// be encrypted; `shift` represents the amount by which each letter in the
// message is to be shifted.

#include <ctype.h>
#include <stdio.h>

#define MSG_SIZE 81

void encrypt(char *msg, int shift);

int main(void) {
  printf("enter message to be encrypted: ");
  char msg[MSG_SIZE], *p = msg;

  int ch;
  while ((ch = getchar()) != '\n' && p < msg + MSG_SIZE) {
    *p++ = ch;
  }
  *p = '\0';

  int shift;
  printf("enter shift amount (1-25): ");
  scanf("%d", &shift);

  encrypt(msg, shift);
  fprintf(stdout, "encrypted message: %s\n", msg);

  return 0;
}

void encrypt(char *msg, int shift) {
  char ch;
  while ((ch = *msg)) {
    if (!isalpha(ch)) {
      msg++;
      continue;
    }

    char a_ref = 'a';
    char uppercase = toupper(ch);
    if (*msg == uppercase) {
      a_ref = 'A';
    }

    *msg = ((ch - a_ref) + shift) % 26 + a_ref;
    msg++;
  }
}
