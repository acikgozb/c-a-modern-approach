// Prints a table of squares using a while statement.

#include <stdio.h>
int main(void) {
  printf("this program prints a table of squares.\n");

  int num;
  printf("enter number of entries in table: ");
  scanf("%d", &num);

  int i = 1;
  while (i <= num) {
    printf("\t%d\t%d\n", i, i * i);
    i++;
  }

  return 0;
}
