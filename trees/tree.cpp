#include <bits/stdc++.h>
using namespace std;
typedef struct TreeNode {
  TreeNode *lChild;
  int data;
  TreeNode *rChild;
} TreeNode;

TreeNode *createTree() {
  TreeNode *current = nullptr;
  TreeNode *temp = nullptr;

  int x;
  queue<TreeNode *> q;

  printf("Enter Root Value - ");
  cin >> x;

  TreeNode *root = (TreeNode *)malloc(sizeof(TreeNode));
  root->data = x;
  root->lChild = nullptr;
  root->rChild = nullptr;

  q.emplace(root);
  while (!q.empty()) {
    current = q.front();
    q.pop();

    cout << "Enter Left Child of " << current->data << " - ";
    cin >> x;

    if (x != -1) {
      temp = (TreeNode *)malloc(sizeof(TreeNode));
      temp->data = x;
      temp->lChild = nullptr;
      temp->rChild = nullptr;

      current->lChild = temp;
      q.emplace(temp);
    }

    cout << "Enter Right Child of " << current->data << " - ";
    cin >> x;

    if (x != -1) {
      temp = (TreeNode *)malloc(sizeof(TreeNode));
      temp->data = x;
      temp->lChild = nullptr;
      temp->rChild = nullptr;

      current->rChild = temp;
      q.emplace(temp);
    }
  }

  return root;
}

void preOrder(TreeNode *root) {
  TreeNode *current = root;

  if (current == nullptr) {
    return;
  }
  cout << current->data << " ";
  preOrder(current->lChild);
  preOrder(current->rChild);
}

void searchTree(TreeNode *root, int key) {
  TreeNode *current = root;

  int isFound = 0;

  if (current == nullptr) {
    printf("Not Found");
    return;
  }

  if (current->data == key) {
    isFound = 1;

  } else if (current->data < key) {
    searchTree(current->rChild, key);

  } else if (current->data > key) {
    searchTree(current->lChild, key);
  }

  if (isFound == 1)
    cout << "Found";
}

void insertInBinaryTree(TreeNode *root, int key) {
  TreeNode *current = root;
  TreeNode *tail = nullptr;

  while (current != nullptr) {
    tail = current;
    if (key == current->data) {
      cout << "Data already exists in BST" << "\n";
      return;
    } else if (key > current->data) {
      current = current->rChild;

    } else if (key < current->data) {
      current = current->lChild;
    }
  }

  if (current == nullptr) {
    if (key > tail->data) {
      tail->rChild = (TreeNode *)malloc(sizeof(TreeNode));
      tail->rChild->data = key;
    } else if (key < tail->data) {
      tail->lChild = (TreeNode *)malloc(sizeof(TreeNode));
      tail->lChild->data = key;
    }
  }
}

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

void inOrder(TreeNode *root) {
  TreeNode *current = root;

  if (current != nullptr) {
    inOrder(current->lChild);
    cout << current->data << " ";
    inOrder(current->rChild);
  }
}

int main() {
  int n;
  cout << "Enter number of keys - ";
  cin >> n;

  int keys[n];

  for (int i = 0; i < n; i++) {
    cout << "Enter value - ";
    cin >> keys[i];
  }
  TreeNode *root = createBinaryTree(keys, n);

  preOrder(root);
  printf("\n");

  int key;
  cout << "Enter to find : ";
  cin >> key;

  searchTree(root, key);

  int key2;
  cout << "Enter value to insert in BST : ";
  cin >> key2;
  insertInBinaryTree(root, key2);

  preOrder(root);
}
