#include <bits/stdc++.h>
using namespace std;

typedef struct TreeNode {

  TreeNode *lChild;
  int data;
  TreeNode *rChild;

} TreeNode;

void heapify(vector<int> &arr, int n, int i) {
  int current = i;

  while (true) {
    int largest = current;
    int left = 2 * current + 1;
    int right = 2 * current + 2;

    if (left < n && arr[left] > arr[largest]) {
      largest = left;
    }

    if (right < n && arr[right] > arr[largest]) {
      largest = right;
    }

    if (largest != current) {
      swap(arr[current], arr[largest]);
      current = largest;
    } else {
      break;
    }
  }
}
