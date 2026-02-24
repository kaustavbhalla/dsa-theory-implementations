#include <stdio.h>

void insertionSort(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    int key = arr[i];
    int j = i - 1;

    while (j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      j--;
    }

    arr[j + 1] = key;
  }
}

void printArray(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    printf("%d\n", arr[i]);
  }
}

int main() {
  int arr[] = {64, 34, 25, 12, 22, 11, 90};
  int n = sizeof(arr) / sizeof(arr[0]);

  printf("Original array: \n");
  printArray(arr, n);

  insertionSort(arr, n);

  printf("Sorted array: \n");
  printArray(arr, n);

  return 0;
}
