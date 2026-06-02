#include <bits/stdc++.h>
using namespace std;

struct Node {
  struct Node *left;
  int data;
  struct Node *right;
};

void searchBST(int key, struct Node *root) {
  struct Node *curr = root;

  if (root == nullptr) {
    return;
  }

  if (key == curr->data) {
    printf("Value found");
    return;
  } else if (key > curr->data) {
    searchBST(key, curr->right);
  } else if (key < curr->data) {
    searchBST(key, curr->left);
  }
}
