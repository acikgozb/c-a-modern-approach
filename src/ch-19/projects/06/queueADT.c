#include "queueADT.h"
#include <stdlib.h>

// SOLUTION (2): Store the size given by the user.
// SOLUTION (3): Convert the fixed-size `contents` array
// to a dynamically-sized array.
// NOTE: `Item *contents` does not indicate that the field
// is actually an array.
// For the context please see the `create` function.
struct queue_type {
  Item *contents;
  int top;
  int bottom;
  int size;
};

static bool is_full(const Queue q);

// Creates a new Queue.
//
// This function returns a NULL pointer when there is not enough
// memory to create a Queue.
Queue create(int size) {
  Queue q = malloc(sizeof(struct queue_type));
  if (q == NULL) {
    return NULL;
  }

  // SOLUTION (4): Allocate mem for Queue's underlying array
  // based on the given size.
  q->contents = malloc(sizeof(Item) * size);
  if (q->contents == NULL) {
    free(q);
    return NULL;
  }

  q->top = 0;
  q->bottom = 0;
  q->size = size;

  return q;
}

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

// Destroys a queue.
// The caller should call `destroy` to free the memory allocated
// for `q`.
// Reading `q` after it's destroyed causes undefined behavior.
void destroy(Queue q) {
  // SOLUTION (4): When destroying Queue, free the memory allocated
  // for it's array as well.
  free(q->contents);
  free(q);
}

static bool is_full(Queue q) { return (q->top - q->bottom) == q->size; }
