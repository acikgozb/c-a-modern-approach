#include "queueADT.h"
#include <stdlib.h>

#define QUEUE_SIZE 20

// SOLUTION (2): Make the incomplete type complete
// by defining the fields in the `.c` file.
struct queue_type {
  void *contents[QUEUE_SIZE];
  int top;
  int bottom;
};

// SOLUTION (3): Define the functions that are declared
// under `queueADT.h`.
static bool is_full(const Queue q);

// Inserts an item to the end of a Queue.
// If Queue is full, `queue` returns a NULL pointer and does not change given
// `q`.
// If Queue is not full, `queue` returns the new Queue with the item added.
// The caller may or may not re-assign `q` to the returned pointer.
Queue enqueue(Queue q, void *item) {
  if (is_full(q)) {
    return NULL;
  }

  q->contents[q->top++] = item;

  return q;
}

// Removes an item from the beginning of a Queue.
// If Queue is full, `dequeue` returns a NULL pointer and does not change given
// `q`.
// If Queue is not full, `queue` returns the Item from the beginning of `q`.
Item dequeue(Queue q) {
  if (is_empty(q)) {

    // NOTE: Since the implementation details are left to the users,
    // I've decided to reset the pointers of a given Queue when it's empty.
    // The same functionality can be achieved by not resetting them,
    // but if we do not reset then we would end up with a different set of
    // top-bottom pointers each time a Queue gets emptied.
    q->top = 0;
    q->bottom = 0;

    return NULL;
  }

  return q->contents[q->bottom++];
}

// Returns the first item in a Queue.
// This operation does not change the Queue.
//
// If Queue is full, `peek_first` returns a NULL pointer.
Item peek_first(const Queue q) {
  if (is_empty(q)) {
    return NULL;
  }

  return q->contents[q->bottom];
}

// Returns the last item in a Queue.
// This operation does not change the Queue.
//
// If Queue is empty, `peek_last` returns a NULL pointer.
Item peek_last(const Queue q) {
  if (is_empty(q)) {
    return NULL;
  }

  return q->contents[q->top - 1];
}

// Returns whether the Queue is empty or not.
bool is_empty(const Queue q) { return (q->top - q->bottom) == 0; }

// Creates a new Queue.
//
// This function returns a NULL pointer when there is not enough
// memory to create a Queue.
Queue create(void) {
  Queue q = malloc(sizeof(struct queue_type));
  if (q == NULL) {
    return NULL;
  }

  q->top = 0;
  q->bottom = 0;

  return q;
}

// Destroys a queue.
// The caller should call `destroy` to free the memory allocated
// for `q`.
// Reading `q` after it's destroyed causes undefined behavior.
void destroy(Queue q) { free(q); }

static bool is_full(Queue q) { return (q->top - q->bottom) == QUEUE_SIZE; }
