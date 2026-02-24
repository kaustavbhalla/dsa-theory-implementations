#include <bits/stdc++.h>

int getMax(const std::vector<int> &arr) {
  int max_val = arr[0];
  for (size_t i = 1; i < arr.size(); i++) {
    if (arr[i] > max_val) {
      max_val = arr[i];
    }
  }
  return max_val;
}

void countSort(std::vector<int> &arr, int exp) {
  int n = arr.size();
  std::vector<int> output(n);
  int count[10] = {0};

  for (int i = 0; i < n; i++) {
    int digit = (arr[i] / exp) % 10;
    count[digit]++;
  }

  for (int i = 1; i < 10; i++) {
    count[i] += count[i - 1];
  }

  for (int i = n - 1; i >= 0; i--) {
    int digit = (arr[i] / exp) % 10;
    output[count[digit] - 1] = arr[i];
    count[digit]--;
  }

  for (int i = 0; i < n; i++) {
    arr[i] = output[i];
  }
}

void radixSort(std::vector<int> &arr) {
  if (arr.empty())
    return;

  int max_val = getMax(arr);

  for (int exp = 1; max_val / exp > 0; exp *= 10) {
    countSort(arr, exp);
  }
}

void printArray(const std::vector<int> &arr) {
  for (int num : arr) {
    std::cout << num << " ";
  }
  std::cout << "\n";
}

int main() {
  std::vector<int> arr = {170, 45, 75, 90, 802, 24, 2, 66};

  std::cout << "Original array: \n";
  printArray(arr);

  radixSort(arr);

  std::cout << "Sorted array: \n";
  printArray(arr);

  return 0;
}
