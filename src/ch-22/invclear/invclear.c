// Modifies a file of part records by setting the quantity on hand to zero for
// all records.

#include "inv.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  // NOTE: In the book, the file `inventory.dat` is not shown
  // or provided in any way.
  //
  // Therefore, I updated the example a little bit to generate
  // two inventories, the first one is the original, the second
  // is the one that this example uses.
  generate_inv("inventory.dat", MAX_PARTS);
  generate_inv("inventory2.dat", MAX_PARTS);

  FILE *fp;
  if ((fp = fopen("inventory2.dat", "rb+")) == NULL) {
    fprintf(stderr, "can't open inventory file\n");
    exit(EXIT_FAILURE);
  }

  struct part inventory[MAX_PARTS];
  int num_parts = fread(inventory, sizeof(struct part), MAX_PARTS, fp);
  for (int i = 0; i < num_parts; i++) {
    inventory[i].on_hand = 0;
  }

  // NOTE: `rewind` needs to be called to set the file position
  // back to the beginning of the file to overwrite the previous contents.
  // If we don't use `rewind`, we append the changes instead.
  rewind(fp);
  fwrite(inventory, sizeof(struct part), num_parts, fp);
  fclose(fp);

  return 0;
}
