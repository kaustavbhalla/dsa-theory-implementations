#include <stdbool.h>
#include <stdio.h>
#define QUEUE_LEN 5

int front = 0;
int back = -1;
int size = 0;

void enqueue(int arr[], int data) {
  if (size == QUEUE_LEN) {
    printf("Queue OverFlow!\n");
    return;
  }
  back++;
  arr[back] = data;
  size++;
}

void dequeue(int arr[]) {
  if (size == 0) {
    printf("Queue Underflow!\n");
    return;
  }
  printf("Dequeued: %d\n", arr[front]);

  for (int i = 0; i < back; i++) {
    arr[i] = arr[i + 1];
  }

  back--;
  size--;
}

void peek(int arr[]) {
  if (size == 0) {
    printf("Queue Underflow!\n");
    return;
  }

  printf("Peek: %d\n", arr[front]);
}

bool isEmpty(int arr[]) {
  if (size == 0) {
    return true;
  } else {
    return false;
  }
}

bool isFull(int arr[]) {
  if (size == QUEUE_LEN) {
    return true;
  } else {
    return false;
  }
}

int main() {}
