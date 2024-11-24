#include "queueDLL.h"
#include <stdio.h>
#include <stdlib.h>

QueueNode *dequeue(Queue *queue) {
  if (isEmpty(queue)) {
    return NULL; // Queue is empty
  }

  QueueNode *temp = queue->front;
  queue->front = queue->front->next;
  if (queue->front != NULL) {
    queue->front->prev = NULL;
  } else {
    queue->rear = NULL; // Handle single element case
  }
  queue->size--;

  return temp;
}
