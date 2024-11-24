#include "queueDLL.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int enqueue(Queue *queue, const char *firstName, const char *middleName, const char *lastName, const char *mobileNo, const char *emailAddress) {
  QueueNode *newNode = (QueueNode *)malloc(sizeof(QueueNode));
  if (newNode == NULL) {
    return -1; // Allocation failed
  }

  strcpy(newNode->firstName, firstName);
  strcpy(newNode->middleName, middleName);
  strcpy(newNode->lastName, lastName);
  strcpy(newNode->mobileNo, mobileNo);
  strcpy(newNode->emailAddress, emailAddress);
  newNode->prev = NULL;
  newNode->next = NULL;

  if (isEmpty(queue)) {
    queue->front = queue->rear = newNode;
  } else {
    queue->rear->next = newNode;
    newNode->prev = queue->rear;
    queue->rear = newNode;
  }
  queue->size++;
  return 0; // Success
}
