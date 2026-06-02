#include <stdio.h>

void selectionSort(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    int minIndex = i;

    for (int j = i + 1; j < n; j++) {
      if (arr[j] < arr[minIndex]) {
        minIndex = j;
      }
    }

    int temp = arr[i];
    arr[i] = arr[minIndex];
    arr[minIndex] = temp;
  }
}

int main() {
  int arr[] = {34, 1, 23, 109, 2, 0, 11};
  int n = sizeof(arr) / sizeof(arr[0]);
  selectionSort(arr, n);

  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
  return 0;
}
