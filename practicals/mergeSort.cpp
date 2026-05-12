#include <bits/stdc++.h>
using namespace std;

void mergeS(vector<int> &arr, int low, int mid, int high) {
  int left = low;
  int right = mid + 1;

  vector<int> temp;

  while (left <= mid && right <= high) {
    if (arr[left] <= arr[right]) {
      temp.emplace_back(arr[left]);
      left++;
    } else if (arr[left] > arr[right]) {
      temp.emplace_back(arr[right]);
      right++;
    }
  }

  while (left <= mid) {
    temp.emplace_back(arr[left]);
    left++;
  }

  while (right <= high) {
    temp.emplace_back(arr[right]);
    right++;
  }

  for (int i = low; i <= high; i++) {
    arr[i] = temp[i - low];
  }
}

void mergeSort(vector<int> &arr, int low, int high) {
  if (low >= high) {
    return;
  }
  int mid = (high + low) / 2;

  mergeSort(arr, low, mid);
  mergeSort(arr, mid + 1, high);

  mergeS(arr, low, mid, high);
}
