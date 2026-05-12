#include <stdio.h>
#include <stdlib.h>

void heapify(int arr[], int n, int i) {
  int largest = i;

  int left = 2 * i + 1;
  int right = 2 * i + 2;

  if ((left < n) && (arr[left] > arr[largest])) {
    largest = left;
  }

  if ((right < n) && (arr[right] > arr[largest])) {
    largest = right;
  }

  if (largest != i) {
    int temp = arr[i];
    arr[i] = arr[largest];
    arr[largest] = temp;

    heapify(arr, n, largest);
  }
}

void buildHeap(int arr[], int n) {
  int s = (n / 2) - 1;

  for (int i = s; i >= 0; i--) {
    heapify(arr, n, i);
  }
}

void deleteFromHeap(int arr[], int *n) {
  int lE = arr[*n - 1];
  arr[0] = lE;
  (*n)--;

  heapify(arr, *n, 0);
}

void insertHeapifyUp(int arr[], int n, int i) {
  int parent = (n - 1) / 2;
  if (parent >= 0) {
    if (arr[i] > arr[parent]) {
      int temp = arr[i];
      arr[i] = arr[parent];
      arr[parent] = i;

      heapify(arr, n, parent);
    }
  }
}

void insertToHeap(int arr[], int *n, int key) {
  (*n)++;
  arr[*n - 1] = key;

  heapify(arr, *n, *n - 1);
}
