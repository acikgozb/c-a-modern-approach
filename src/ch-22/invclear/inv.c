#include "inv.h"
#include <stdio.h>

enum error_kind {
  EINVLEN = -1,
  EINVOP = -2,
  EINVWR = -3,
};

int generate_inv(const char *name, int len) {
  if (len > MAX_PARTS) {
    fprintf(stderr, "cannot generate inventory: len %d exceeds the limit %d",
            len, MAX_PARTS);
    return EINVLEN;
  }

  FILE *fp;
  if ((fp = fopen(name, "wb")) == NULL) {
    return EINVOP;
  }

  struct part inventory[len];
  for (int i = 0; i < len; i++) {
    sprintf(inventory[i].name, "part-%d", i);
    inventory[i].number = i;
    // NOTE: This field is alternated between 0 and 1 to see the changes done by
    // the original example in the book.
    // We can diff the binary files to see the different bytes:
    // ```bash
    // cmp -l ./inventory.dat ./inventory2.dat
    // ```
    inventory[i].on_hand = i % 2;
  }

  int w_len = fwrite(inventory, sizeof(struct part), len, fp);
  fclose(fp);

  if (w_len != len) {
    remove(name);
    fprintf(stderr,
            "cannot generate inventory: partial write occurred: failed to "
            "write %d part(s) out of %d parts",
            len - w_len, len);
    return EINVWR;
  }

  return 0;
}
