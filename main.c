#include "queueDLL.h"
#include <stdio.h>
#include <string.h>

int main() {
  Queue queue;
  queue.front = queue.rear = NULL;
  queue.size = 0;

  char firstName[50], middleName[50], lastName[50], mobileNo[20], emailAddress[100];

  while (1) {
    printf("\nMenu:\n");
    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. Show\n");
    printf("4. Exit\n");

    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        printf("Enter first name: ");
        fgets(firstName, sizeof(firstName), stdin);
        firstName[strcspn(firstName, "\n")] = 0; // Remove newline character

        printf("Enter middle name: ");
        fgets(middleName, sizeof(middleName), stdin);
        middleName[strcspn(middleName, "\n")] = 0;

        printf("Enter last name: ");
        fgets(lastName, sizeof(lastName), stdin);
        lastName[strcspn(lastName, "\n")] = 0;

        printf("Enter mobile number: ");
        fgets(mobileNo, sizeof(mobileNo), stdin);
        mobileNo[strcspn(mobileNo, "\n")] = 0;

        printf("Enter email address: ");
        fgets(emailAddress, sizeof(emailAddress), stdin);
        emailAddress[strcspn(emailAddress, "\n")] = 0;

        if (enqueue(&queue, firstName, middleName, lastName, mobileNo, emailAddress) == 0) {
          printf("Person successfully added to the queue.\n");
        } else {
          printf("Error adding person to the queue.\n");
        }
        break;

      case 2:
        QueueNode *dequeuedPerson = dequeue(&queue);
        if (dequeuedPerson != NULL) {
          printf("Person dequeued:\n");
          printf("\tLast Name: %s\n", dequeuedPerson->lastName);
          printf("\tFirst Name: %s\n", dequeuedPerson->firstName);
          printf("\tMiddle Name: %s\n", dequeuedPerson->middleName);
          printf("\tMobile No.: %s\n", dequeuedPerson->mobileNo);
          printf("\tEmail Address: %s\n", dequeuedPerson->emailAddress);
          free(dequeuedPerson);
        } else {
          printf("Queue is empty.\n");
        }
        break;

      case 3:
        show(&queue);
        break;

      case 4:
        printf("Exiting...\n");
        exit(0);

      default:
        printf("Invalid choice.\n");
    }
  }

  return 0;
}
