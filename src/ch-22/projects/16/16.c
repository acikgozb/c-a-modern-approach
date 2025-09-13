// Modify the `fcopy.c` program of Section 22.4 so that it uses `fread` and
// `fwrite` to copy the file in blocks of 512 bytes. (The last block may contain
// fewer than 512 bytes, of course).

// NOTE: To test this project, you can create a dummy source file `src` that
// contains X bytes.
// For Linux hosts, you can use the chain of commands below:
// ```bash
// dd if=/dev/urandom of=src bs=700c count=1
// ./fcopy ./src ./out
// diff ./src ./out
// echo $? # 0, files are the same.
// ```

#include <stdio.h>
#include <stdlib.h>

#define CP_BLOCK_SIZE 512

int main(int argc, char **argv) {
  FILE *src, *dest;

  if (argc != 3) {
    fprintf(stderr, "usage: fcopy <src> <dest>");
    exit(EXIT_FAILURE);
  }

  if ((src = fopen(argv[1], "rb")) == NULL) {
    fprintf(stderr, "can't open %s\n", argv[1]);
    exit(EXIT_FAILURE);
  }

  if ((dest = fopen(argv[2], "wb")) == NULL) {
    fprintf(stderr, "can't open %s\n", argv[2]);
    exit(EXIT_FAILURE);
  }

  char block[CP_BLOCK_SIZE];
  int nmemb = 0;
  while ((nmemb = fread(block, sizeof(block[0]), CP_BLOCK_SIZE, src)) != 0) {
    fwrite(block, sizeof(block[0]), nmemb, dest);
  }

  fclose(src);
  fclose(dest);

  return 0;
}
