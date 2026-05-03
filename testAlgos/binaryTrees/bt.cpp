#include <bits/stdc++.h>
using namespace std;

typedef struct TreeNode {
  TreeNode *lChild;
  int data;
  TreeNode *rChild;
} TreeNode;

TreeNode *createBinaryTree() {
  int x;
  cout << "Enter root node: ";
  cin >> x;

  TreeNode *root = new TreeNode;
  root->data = x;
  root->lChild = nullptr;
  root->rChild = nullptr;

  queue<TreeNode *> q;
  q.emplace(root);

  while (!q.empty()) {
    TreeNode *current = q.front();
    q.pop();

    int leftVal, rightVal;

    cout << "Enter left child for " << current->data << " : ";
    cin >> leftVal;

    if (leftVal != -1) {
      TreeNode *temp = new TreeNode;
      temp->data = leftVal;
      temp->lChild = nullptr;
      temp->rChild = nullptr;

      current->lChild = temp;
      q.emplace(temp);
    }

    cout << "Enter left child for " << current->data << " : ";
    cin >> rightVal;

    if (rightVal != -1) {
      TreeNode *temp = new TreeNode;
      temp->data = rightVal;
      temp->lChild = nullptr;
      temp->rChild = nullptr;

      current->rChild = temp;
      q.emplace(temp);
    }
  }

  return root;
}

void preOrder(TreeNode *root) {
  if (root == nullptr) {
    return;
  }
  cout << root->data << " ";
  preOrder(root->lChild);
  preOrder(root->rChild);
}

int main() {
  TreeNode *root = createBinaryTree();
  preOrder(root);
}
