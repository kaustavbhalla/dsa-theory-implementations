#include <bits/stdc++.h>
#include <utility>
using namespace std;

int sortQuick(vector<int> &arr, int low, int high) {
  int pivot = arr[low];

  int left = low;
  int right = high;

  while (left < right) {
    while (arr[left] <= pivot && left <= high - 1) {
      left++;
    }

    while (arr[right] > pivot && right >= low + 1) {
      right--;
    }
    if (left < right) {
      swap(arr[left], arr[right]);
    }
  }

  swap(arr[low], arr[right]);

  return right;
}

void quickSort(vector<int> &arr, int low, int high) {
  if (low >= high) {
    return;
  }
  int partition = sortQuick(arr, low, high);

  quickSort(arr, low, partition - 1);
  quickSort(arr, partition + 1, high);
}
