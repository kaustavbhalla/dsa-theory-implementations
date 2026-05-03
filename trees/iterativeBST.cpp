#include <bits/stdc++.h>
using namespace std;
typedef struct TreeNode {
  TreeNode *lChild;
  int data;
  TreeNode *rChild;
} TreeNode;

TreeNode *createBinaryTree(int keys[], int n) {
  TreeNode *root = (TreeNode *)malloc(sizeof(TreeNode));
  root->data = keys[0];
  root->lChild = nullptr;
  root->rChild = nullptr;
  TreeNode *current = root;
  TreeNode *tail;

  for (int i = 1; i < n; i++) {

    while (current != nullptr) {
      tail = current;

      if (keys[i] < current->data) {
        current = current->lChild;
      } else if (keys[i] > current->data) {
        current = current->rChild;
      } else {
        break;
      }
    }
    if (keys[i] < tail->data) {
      tail->lChild = (TreeNode *)malloc(sizeof(TreeNode));
      tail->lChild->data = keys[i];

      tail->lChild->lChild = nullptr;
      tail->lChild->rChild = nullptr;
      current = root;
    } else if (keys[i] > tail->data) {
      tail->rChild = (TreeNode *)malloc(sizeof(TreeNode));
      tail->rChild->data = keys[i];

      tail->rChild->lChild = nullptr;
      tail->rChild->rChild = nullptr;
      current = root;
    }
  }
  return root;
}

void iterativePreOrder(TreeNode *root) {
  if (root == nullptr) {
    return;
  }

  stack<TreeNode *> s;
  s.push(root);

  while (!s.empty()) {
    TreeNode *curr = s.top();
    s.pop();

    cout << curr->data << " ";

    if (curr->rChild) {
      s.push(curr->rChild);
    }
    if (curr->lChild) {
      s.push(curr->lChild);
    }
  }
}

void iterativeInOrder(TreeNode *root) {
  stack<TreeNode *> s;
  TreeNode *curr = root;

  while (curr != nullptr || !s.empty()) {
    while (curr != nullptr) {
      s.push(curr);
      curr = curr->lChild;
    }

    curr = s.top();
    s.pop();

    cout << curr->data << " ";

    curr = curr->rChild;
  }
}

int main() {
  int n;
  cin >> n;

  int keys[n];
  for (int i = 0; i < n; i++) {
    cin >> keys[i];
  }

  TreeNode *root = createBinaryTree(keys, n);

  iterativeInOrder(root);
}
