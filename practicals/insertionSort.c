#include <stdio.h>

void insertionSort(int arr[], int n) {
  for (int i = 1; i < n; i++) {
    int key = arr[i];
    int j = i - 1;

    while (j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = key;
  }
}

int main(void) {
  int arr[] = {21, 13, 2, 54, 1, 55};
  insertionSort(arr, sizeof(arr) / sizeof(arr[0]));

  int n = sizeof(arr) / sizeof(arr[0]);

  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
}
