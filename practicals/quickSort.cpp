#include <bits/stdc++.h>
using namespace std;

int quickS(vector<int> &arr, int low, int high) {
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
  int partEle = quickS(arr, low, high);

  quickSort(arr, low, partEle - 1);
  quickSort(arr, partEle + 1, high);
}
