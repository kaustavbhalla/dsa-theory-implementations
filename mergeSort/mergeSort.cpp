#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr, int low, int mid, int high) {
  vector<int> temp;
  int left = low;
  int right = mid + 1;

  while ((left <= mid) && (right <= high)) {
    if (arr[left] <= arr[right]) {
      temp.emplace_back(arr[left]);
      left++;
    } else {
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
  if (low >= high)
    return;

  int mid = (low + high) / 2;
  mergeSort(arr, low, mid);
  mergeSort(arr, mid + 1, high);

  merge(arr, low, mid, high);
}

int main() {
  vector<int> a = {3, 1, 2, 4, 1, 5, 6, 2, 4};
  mergeSort(a, 0, a.size() - 1);

  for (int x : a) {
    cout << x << " ";
  }

  cout << "\n";
}
