#include <stdio.h>

int sortQuick(int arr[], int low, int high) {
  int partEle = arr[low];
  int left = low;
  int right = high;

  while (left < right) {
    while ((arr[left] <= partEle) && (left <= high - 1)) {
      left++;
    }

    while ((arr[right] > partEle) && (right > low)) {
      right--;
    }

    if (left < right) {
      int temp = arr[left];
      arr[left] = arr[right];
      arr[right] = temp;
    }
  }

  int temp2 = arr[low];
  arr[low] = arr[right];
  arr[right] = temp2;

  return right;
}

void quickSort(int arr[], int low, int high) {
  if (low >= high) {
    return;
  }

  int partition = sortQuick(arr, low, high);
  quickSort(arr, low, partition - 1);
  quickSort(arr, partition + 1, high);
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

  quickSort(arr, 0, n);

  printf("Sorted array: \n");
  printArray(arr, n);

  return 0;
}
