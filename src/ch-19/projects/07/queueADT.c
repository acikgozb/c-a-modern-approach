#include "queueADT.h"
#include <stdlib.h>

// SOLUTION (1): Define the node of a linked list.
struct node {
  Item data;
  struct node *next;
};

// SOLUTION (2): Keep `queue_type` to maintain the interface
// we have in the header file.
struct queue_type {
  struct node *top;
  struct node *bottom;
};

static bool is_full(const Queue q);

// Inserts an item to the end of a Queue.
// If Queue is full, `queue` returns a NULL pointer and does not change given
// `q`.
// If Queue is not full, `queue` returns the new Queue with the item added.
// The caller may or may not re-assign `q` to the returned pointer.
Queue enqueue(Queue q, Item item) {
  if (is_full(q)) {
    return NULL;
  }

  // SOLUTION (3): For each enqueue operation,
  // allocate memory for each node and set initialize
  // fields accordingly.
  struct node *n = malloc(sizeof(struct node));
  if (n == NULL) {
    return NULL;
  }
  n->data = item;
  n->next = NULL;

  // SOLUTION (4): When a new node is
  // enqueued, set the given `Queue`'s
  // state accordingly.
  if (q->top != NULL) {
    q->top->next = n;
  }
  q->top = n;

  if (q->bottom == NULL) {
    q->bottom = n;
  }

  return q;
}

// Removes an item from the beginning of a Queue.
// If Queue is full, `dequeue` returns a NULL pointer and does not change given
// `q`.
// If Queue is not full, `queue` returns the Item from the beginning of `q`.
Item dequeue(Queue q) {
  if (is_empty(q)) {
    return NULL;
  }

  struct node *n = q->bottom;
  struct node *next = n->next;

  // SOLUTION (6): For each dequeue
  // operation, set the given `Queue`'s state
  // accordingly.
  if (q->top == q->bottom) {
    q->top = NULL;
  }
  q->bottom = next;

  Item item = n->data;
  // NOTE: From clients' perspective, they do not
  // know the underlying Queue implementation unless
  // we explicitly tell them.
  // Therefore, it is not a good idea for this specific
  // program to delegate the memory cleanup of a node to the
  // client.
  // That is why we explicitly free the memory allocated for
  // the node we're dequeue'ing from a given `Queue`.
  free(n);

  return item;
}

// Returns the first item in a Queue.
// This operation does not change the Queue.
//
// If Queue is full, `peek_first` returns a NULL pointer.
Item peek_first(const Queue q) {
  if (is_empty(q)) {
    return NULL;
  }

  return q->bottom->data;
}

// Returns the last item in a Queue.
// This operation does not change the Queue.
//
// If Queue is empty, `peek_last` returns a NULL pointer.
Item peek_last(const Queue q) {
  if (is_empty(q)) {
    return NULL;
  }

  return q->top->data;
}

// Returns whether the Queue is empty or not.
// SOLUTION (7): `Queue` becomes empty when `Queue` does not
// hold any reference to any of the nodes.
bool is_empty(const Queue q) { return q->top == NULL && q->bottom == NULL; }

// Creates a new Queue.
//
// This function returns a NULL pointer when there is not enough
// memory to create a Queue.
Queue create(void) {
  Queue q = malloc(sizeof(struct queue_type));
  if (q == NULL) {
    return NULL;
  }

  // SOLUTION (8): Set the initial state of `Queue` accordingly.
  // Keep in mind that we're working entirely on pointers when it
  // comes to linked lists.
  q->top = NULL;
  q->bottom = NULL;

  return q;
}

// Destroys a queue.
// The caller should call `destroy` to free the memory allocated
// for `q`.
// Reading `q` after it's destroyed causes undefined behavior.
void destroy(Queue q) {
  // SOLUTION (9): We explicitly go through the list
  // until it's empty to free the memory allocated for
  // each node we have in `Queue`.
  while (!is_empty(q)) {
    dequeue(q);
  }

  free(q);
}

// NOTE: Returning false signifies that there is no limit
// in the program for the linked list implementation.
// In short, as long as we have memory, our queue is not full.
static bool is_full(Queue q) { return false; }
