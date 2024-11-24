#include "queueDLL.h"
#include <stdio.h>
#include <string.h>

void getUserInput(char *firstName, char *middleName, char *lastName, char *mobileNo, char *emailAddress) {
  printf("Enter first name (or 'q' to quit): ");
  fgets(firstName, sizeof(firstName), stdin);
  firstName[strcspn(firstName, "\n")] = 0; // Remove newline character

  if (strcmp(firstName, "q") == 0) {
    return;
  }

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
}
