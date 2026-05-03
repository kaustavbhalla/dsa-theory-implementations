#include <bits/stdc++.h>
using namespace std;

int sortQuick(vector<int> &arr, int low, int high) {
  int partEle = arr[low];
  int left = low;
  int right = high;

  while (left <= right) {
    while ((arr[left] <= partEle) && left <= high - 1) {
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

void quickSort(vector<int> &arr, int low, int high) {
  if (low >= high) {
    return;
  }
  int partition = sortQuick(arr, low, high);

  quickSort(arr, low, partition - 1);
  quickSort(arr, partition + 1, high);
}

int main() {
  vector<int> arr = {27, 3, 45, 21, 9, 10};
  quickSort(arr, 0, arr.size() - 1);

  for (auto x : arr) {
    cout << x << " ";
  }

  cout << "\n";
}
