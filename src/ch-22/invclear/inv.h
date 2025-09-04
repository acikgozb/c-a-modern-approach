#ifndef INV_H
#define INV_H

#include <stdio.h>

#define NAME_LEN 25
#define MAX_PARTS 100

struct part {
  int number;
  char name[NAME_LEN + 1];
  int on_hand;
};

int generate_inv(const char *name, int len);

#endif
