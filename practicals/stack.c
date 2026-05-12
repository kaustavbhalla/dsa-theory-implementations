#include <stdio.h>
#include <stdlib.h>

#define LEN 100
int st[LEN];
int front = -1;

void push(int data) {
  if (front == 99) {
    printf("Stack overflow\n");
    return;
  }

  st[++front] = data;
}

int pop() {
  if (front == -1) {
    printf("Stack underflow\n");
    return -1;
  }

  int retVal = st[front];
  front--;

  return retVal;
}
