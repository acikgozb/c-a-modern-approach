// Write a program that merges two files containing part records stored by the
// `inventory.c` program in Project 8. Assume that the records in each file are
// sorted by part number, and that we want the resulting file to be sorted as
// well.
//
// If both files have a part with the same number, combine the quantities sorted
// in the records.
//
// As a consistency check, have the program compare the part names and print an
// error message if they don't match. Have the program obtain the names of the
// input files and the merged file from the command line.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LEN 25

struct part {
  int number;
  char name[NAME_LEN];
  int on_hand;
};

#define PART_SIZE sizeof(struct part)

int merge(const char *first, const char *second, const char *merged);

int main(int argc, char **argv) {
  if (argc != 4) {
    fprintf(stderr, "usage: merge <inv1> <inv2> <merged_inv>");
    exit(EXIT_FAILURE);
  }

  int res = merge(argv[1], argv[2], argv[3]);
  return res == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}

int merge(const char *first, const char *second, const char *merged) {
  FILE *f_first = fopen(first, "rb");
  if (f_first == NULL) {
    fprintf(stderr, "error: could not open inventory %s", first);
    return -1;
  }

  FILE *f_second = fopen(second, "rb");
  if (f_second == NULL) {
    fprintf(stderr, "error: could not open inventory %s", second);
    return -1;
  }

  FILE *f_merged = fopen(merged, "wb");
  if (f_merged == NULL) {
    fprintf(stderr, "error: could not create merge file %s", merged);
    return -1;
  }

  struct part p_first, p_second;
  int read_p1 = fread(&p_first, PART_SIZE, 1, f_first);
  int read_p2 = fread(&p_second, PART_SIZE, 1, f_second);

  while (read_p1 == 1 && read_p2 == 1) {
    if (p_first.number > p_second.number) {
      fwrite(&p_second, PART_SIZE, 1, f_merged);
      read_p2 = fread(&p_second, PART_SIZE, 1, f_second);
    } else if (p_second.number > p_first.number) {
      fwrite(&p_first, PART_SIZE, 1, f_merged);
      read_p1 = fread(&p_first, PART_SIZE, 1, f_first);
    } else {
      if (strcmp(p_first.name, p_second.name) != 0) {
        fprintf(stderr,
                "warn: parts have different names for number %d: %s, %s",
                p_first.number, p_first.name, p_second.name);
      }
      p_first.on_hand += p_second.on_hand;
      fwrite(&p_first, PART_SIZE, 1, f_merged);

      read_p1 = fread(&p_first, PART_SIZE, 1, f_first);
      read_p2 = fread(&p_second, PART_SIZE, 1, f_second);
    }
  }

  if (ferror(f_first) || ferror(f_second)) {
    fprintf(stderr, "error: failed to merge inventories\n");
    fclose(f_first);
    fclose(f_second);
    fclose(f_merged);
    remove(merged);
    return -1;
  }

  while (read_p1 == 1) {
    fwrite(&p_first, PART_SIZE, 1, f_merged);
    read_p1 = fread(&p_first, PART_SIZE, 1, f_first);
  }
  if (ferror(f_first)) {
    fprintf(stderr, "error: failed to merge inventories\n");
    fclose(f_first);
    fclose(f_second);
    fclose(f_merged);
    remove(merged);
    return -1;
  }

  while (read_p2 == 1) {
    fwrite(&p_second, PART_SIZE, 1, f_merged);
    read_p2 = fread(&p_second, PART_SIZE, 1, f_second);
  }
  if (ferror(f_second)) {
    fprintf(stderr, "error: failed to merge inventories\n");
    fclose(f_first);
    fclose(f_second);
    fclose(f_merged);
    remove(merged);
    return -1;
  }

  fclose(f_first);
  fclose(f_second);
  fclose(f_merged);

  return 0;
}
