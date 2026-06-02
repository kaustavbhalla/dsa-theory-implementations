#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr, int low, int mid, int high) {
  int left = low;
  int right = mid + 1;

  vector<int> temp;
  while (left <= mid && right <= high) {
    if (arr[left] <= arr[right]) {
      temp.emplace_back(arr[left]);
      left++;
    } else if (arr[right] < arr[left]) {
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

  int mid = (low + high) / 2;

  mergeSort(arr, low, mid);
  mergeSort(arr, mid + 1, high);

  merge(arr, low, mid, high);
}

int main() {
  vector<int> v = {100, 2, 34, 56, 7, 8, 90};
  mergeSort(v, 0, 6);

  for (auto x : v) {
    cout << x << " ";
  }

  cout << "\n";
}
