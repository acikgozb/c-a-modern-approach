#ifndef QUEUE_ADT_H
#define QUEUE_ADT_H

#include <stdbool.h>

typedef struct queue_type *Queue;

// Since the requirements do not specify
// a certain item type, a `void *` is used.
typedef void *Item;

// Inserts an item to the end of a Queue.
Queue enqueue(Queue q, void *item);

// Removes an item from the beginning of a Queue.
Item dequeue(Queue q);

// Returns the first item in a Queue.
// This operation does not change the Queue.
Item peek_first(const Queue q);

// Returns the last item in a Queue.
// This operation does not change the Queue.
Item peek_last(const Queue q);

// Returns whether the Queue is empty or not.
bool is_empty(const Queue q);

// SOLUTION (1): Allow `create` to get a size from the clients
// for a `Queue`.
// Creates a new queue.
Queue create(int size);

// Destroys a queue.
// The caller should call `destroy` to free
// the memory allocated for the queue.
// Reading the queue after it's destroyed
// causes undefined behavior.
void destroy(Queue q);
#endif
