#include <stdio.h>

void selectionSort(int arr[], int n) {

  for (int i = 0; i < n - 1; i++) {
    int minIndex = i;
    for (int j = i + 1; j < n; j++) {
      if (arr[j] < arr[minIndex]) {
        minIndex = j;
      }
    }
    if (minIndex != i) {
      int temp = arr[i];
      arr[i] = arr[minIndex];
      arr[minIndex] = temp;
    }
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

  selectionSort(arr, n);

  printf("Sorted array: \n");
  printArray(arr, n);

  return 0;
}
