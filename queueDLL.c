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

void show(Queue *queue) {
  if (isEmpty(queue)) {
    printf("Queue is empty.\n");
    return;
  }

  QueueNode *temp = queue->front;
  int count = 1;
  while (temp != NULL) {
    printf("Data %d:\n", count);
    printf("\tLast Name: %s\n", temp->lastName);
    printf("\tFirst Name: %s\n", temp->firstName);
    printf("\tMiddle Name: %s\n", temp->middleName);
    printf("\tMobile No.: %s\n", temp->mobileNo);
    printf("\tEmail Address: %s\n", temp->emailAddress);
    temp = temp->next;
    count++;
  }
}

int isEmpty(Queue *queue) {
  return queue->front == NULL;
}
