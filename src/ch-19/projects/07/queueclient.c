// Modify Project 5 so that the items in a queue are stored in a linked list.

#include "queueADT.h"
#include <stdio.h>
#include <stdlib.h>

// NOTE: The error handling is delegated to the client for
// this solution.
// This functionality is not written in the requirements, so this is
// out of the current scope.
void terminate(char *msg, Queue q1, Queue q2);

// SOLUTION (4): Perform operations on multiple `Queue` types.
int main(void) {
  Queue q1, q2, qp;

  q1 = create();
  if (q1 == NULL) {
    terminate("fatal: unable to create q1: out of memory", q1, q2);
  }
  q2 = create();
  if (q2 == NULL) {
    terminate("fatal: unable to create q2: out of memory", q1, q2);
  }

  qp = enqueue(q1, "1");
  if (qp == NULL) {
    terminate("fatal: unable to enqueue the item to q1: queue is full", q1, q2);
  }

  qp = enqueue(q1, "2");
  if (qp == NULL) {
    terminate("fatal: unable to enqueue the item to q1: queue is full", q1, q2);
  }

  printf("first item in q1 is %s\n", (char *)peek_first(q1));
  printf("last item in q1 is %s\n", (char *)peek_last(q1));

  char *s1 = dequeue(q1);
  qp = enqueue(q2, s1);
  if (qp == NULL) {
    terminate("fatal: unable to enqueue the item to q2: queue is full", q1, q2);
  }

  char *s2 = dequeue(q1);
  qp = enqueue(q2, s2);
  if (qp == NULL) {
    terminate("fatal: unable to enqueue the item to q2: queue is full", q1, q2);
  }

  printf("first item in q2 is %s\n", (char *)peek_first(q2));
  printf("last item in q2 is %s\n", (char *)peek_last(q2));

  dequeue(q2);
  dequeue(q2);

  if (is_empty(q2)) {
    printf("q2 is empty\n");
  } else {
    printf("q2 is not empty\n");
  }

  destroy(q1);
  destroy(q2);

  return 0;
}

void terminate(char *msg, Queue q1, Queue q2) {
  fprintf(stderr, "%s\n", msg);

  if (q1 != NULL) {
    destroy(q1);
  }
  if (q2 != NULL) {
    destroy(q2);
  }

  exit(EXIT_FAILURE);
}
