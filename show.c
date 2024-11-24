#include "queueDLL.h"
#include <stdio.h>

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
