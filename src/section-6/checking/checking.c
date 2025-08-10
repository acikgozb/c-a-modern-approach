// Balances a checkbook.

#include <stdio.h>

int main(void) {
  printf("*** ACME checkbook-balancing program ***\n");
  printf("commands: 0=clear, 1=credit, 2=debit, 3=balance, 4=exit\n\n");

  int cmd;
  float balance = 0.0f, credit, debit;

  for (;;) {
    printf("enter command: ");
    scanf("%d", &cmd);

    switch (cmd) {
    case 0:
      balance = 0.0f;
      break;
    case 1:
      printf("enter amount of credit: ");
      scanf("%f", &credit);
      balance += credit;
      break;
    case 2:
      printf("enter amount of debit: ");
      scanf("%f", &debit);
      balance -= debit;
      break;

    case 3:
      printf("current balance: $%.2f\n", balance);
      break;
    case 4:
      return 0;
    default:
      printf("commands: 0=clear, 1=credit, 2=debit, 3=balance, 4=exit\n\n");
      break;
    }
  }
}
