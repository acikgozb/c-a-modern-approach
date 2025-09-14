// Tests signals.

#include <signal.h>
#include <stdio.h>

void handler(int sig);
void raise_sig(void);

int main(void) {
  void (*orig_handler)(int);

  printf("installing handler for signal %d\n", SIGINT);
  orig_handler = signal(SIGINT, handler);
  raise_sig();

  printf("changing handler to SIG_IGN\n");
  signal(SIGINT, SIG_IGN);
  raise_sig();

  printf("restoring original handler\n");
  signal(SIGINT, orig_handler);
  raise_sig();

  printf("program terminates normally\n");
  return 0;
}

void handler(int sig) { printf("handler called for signal %d\n", sig); }

void raise_sig(void) { raise(SIGINT); }
