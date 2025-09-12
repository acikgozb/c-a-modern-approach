// Modify Project 15 from Chapter 8 so that the program prompts the user to
// enter the name of a file containing the message to be encrypted.
//
// The program then writes the encrypted message to a file with the same name
// but an added extension of `.enc`. In this example, the original file name is
// `message.txt`, so the encrypted message will be stored in a file named
// `message.txt.enc`. There's no limit on the size of the file to be encrypted
// or on the length of each line in the file.

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define INPUT_FILENAME_LEN 40
#define OUTPUT_FILENAME_LEN 44

int main(void) {
  printf("enter name of the file to be encyrpted: ");
  char in_filename[INPUT_FILENAME_LEN];
  int ch, i = 0;
  while ((ch = getchar()) != '\n') {
    in_filename[i++] = ch;
  }
  in_filename[i] = '\0';

  FILE *in = fopen(in_filename, "rb");
  if (in == NULL) {
    fprintf(stderr, "error: could not open file: %s\n", in_filename);
    exit(EXIT_FAILURE);
  }

  printf("enter shift amount (1 - 25): ");
  int shift;
  scanf("%d", &shift);

  char out_filename[OUTPUT_FILENAME_LEN];
  sprintf(out_filename, "%s.enc", in_filename);

  FILE *out = fopen(out_filename, "wb");
  if (out == NULL) {
    fprintf(stderr, "error: could not create output file %s\n", out_filename);
    fclose(in);
    exit(EXIT_FAILURE);
  }

  int letter;
  while ((letter = getc(in)) != EOF) {
    if (!isalpha(letter)) {
      putc(letter, out);
      continue;
    }

    char ascii_ref = 'a';
    char uppercase = toupper(letter);
    if (letter == uppercase) {
      ascii_ref = 'A';
    }

    int encrypted_letter = ((letter - ascii_ref) + shift) % 26 + ascii_ref;
    putc(encrypted_letter, out);
  }

  fclose(out);
  fclose(in);
}
