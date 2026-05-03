#include <stdio.h>
#include <stdlib.h>

struct MaxHeap {
  int arr[100];
  int size;
};

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

struct MaxHeap *createMaxHeap() {
  struct MaxHeap *heap = (struct MaxHeap *)malloc(sizeof(struct MaxHeap));
  heap->size = 0;

  return heap;
}

void insertIntoMaxHeap(struct MaxHeap *heap, int data) {
  if (heap->size == 100) {
    printf("Heap is full\n");
    return;
  }

  int currIndex = heap->size;
  heap->arr[currIndex] = data;
  heap->size++;

  int parentIndex = (currIndex - 1) / 2;

  while (currIndex > 0 && heap->arr[currIndex] > heap->arr[parentIndex]) {
    swap(&heap->arr[currIndex], &heap->arr[parentIndex]);

    currIndex = parentIndex;
    parentIndex = (currIndex - 1) / 2;
  }
}

int deleteFromMaxHeap(struct MaxHeap *heap) {
  int retVal = heap->arr[0];

  heap->arr[0] = heap->arr[heap->size - 1];
  heap->size--;

  int i = 0;

  while (1) {
    int left = (2 * i) + 1;
    int right = (2 * i) + 2;
    int parent = (i - 1) / 2;

    int largest = i;

    if (left < heap->size && heap->arr[left] > heap->arr[largest]) {
      largest = left;
    }

    if (left < heap->size && heap->arr[right] > heap->arr[largest]) {
      largest = right;
    }

    if (largest == i) {
      break;
    }

    swap(&heap->arr[i], &heap->arr[largest]);

    i = largest;
  }
  return retVal;
}
