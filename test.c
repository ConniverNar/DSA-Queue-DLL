#include "queueDLL.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void test(){
if (dequeue(&queue) != NULL) {
  // Do something with the dequeued person (if needed)
} else {
  printf("Queue is empty.\n");
}
}
