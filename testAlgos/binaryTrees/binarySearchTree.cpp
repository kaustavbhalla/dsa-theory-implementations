#include <bits/stdc++.h>
using namespace std;

typedef struct TreeNode {
  TreeNode *lChild;
  int data;
  TreeNode *rChild;
} TreeNode;

TreeNode *buildBST(vector<int> &keys) {
  int n = keys.size();
  TreeNode *root = new TreeNode;
  root->data = keys[0];
  root->lChild = nullptr;
  root->rChild = nullptr;

  TreeNode *current, *tail;
  current = root;

  for (int i = 1; i < n; i++) {
    while (current != nullptr) {
      tail = current;

      if (keys[i] > current->data) {
        current = current->rChild;
      } else if (keys[i] < current->data) {
        current = current->lChild;
      } else {
        break;
      }
    }
    if (keys[i] < tail->data) {
      tail->lChild = new TreeNode;
      tail->lChild->data = keys[i];

      tail->lChild->rChild = nullptr;
      tail->lChild->lChild = nullptr;

      current = root;
    } else if (keys[i] > tail->data) {
      tail->rChild = new TreeNode;
      tail->rChild->data = keys[i];

      tail->rChild->lChild = nullptr;
      tail->rChild->rChild = nullptr;

      current = root;
    }
  }
  return root;
}

void insertInBST(TreeNode *root, int key) {
  TreeNode *current = root;
  TreeNode *tail;

  while (current != nullptr) {
    tail = current;

    if (key < current->data) {
      current = current->lChild;
    } else if (key > current->data) {
      current = current->rChild;
    } else if (key == current->data) {
      printf("Can't have duplicates in BST");
      return;
    }
  }

  if (key < tail->data) {
    tail->lChild = new TreeNode;
    tail->lChild->data = key;

    tail->lChild->lChild = nullptr;
    tail->lChild->rChild = nullptr;
  } else if (key > tail->data) {
    tail->rChild = new TreeNode;
    tail->rChild->data = key;

    tail->rChild->lChild = nullptr;
    tail->rChild->rChild = nullptr;
  }
}

void deleteInBST(TreeNode *root, int key) { TreeNode *current = root; }

void inOrder(TreeNode *root) {
  if (root == nullptr) {
    return;
  }

  inOrder(root->lChild);
  cout << root->data << " ";
  inOrder(root->rChild);
}

int main() {
  int n;
  cout << "Enter size of array - ";
  cin >> n;

  vector<int> keys(n);
  for (int i = 0; i < n; i++) {
    cin >> keys[i];
  }

  TreeNode *root = buildBST(keys);
  inOrder(root);

  int valueInsert;
  cout << "Enter value to insert: ";
  cin >> valueInsert;

  insertInBST(root, valueInsert);

  inOrder(root);
}
