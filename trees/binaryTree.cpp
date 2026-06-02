#include <bits/stdc++.h>
using namespace std;

struct Node {
  struct Node *lChild;
  int data;
  struct Node *rChild;
};

struct Node *createBinaryTree() {
  struct Node *root = (struct Node *)malloc(sizeof(struct Node));
  struct Node *current;
  struct Node *temp;

  printf("Enter root value - ");
  scanf("%d", &root->data);

  root->lChild = nullptr;
  root->rChild = nullptr;

  queue<struct Node *> q;
  q.emplace(root);

  while (!q.empty()) {
    current = q.front();
    q.pop();
    int x;

    printf("Enter left node value for %d - ", current->data);
    scanf("%d", &x);

    if (x != -1) {
      temp = (struct Node *)malloc(sizeof(struct Node));
      temp->data = x;

      current->lChild = temp;
      temp->lChild = nullptr;
      temp->rChild = nullptr;

      q.emplace(temp);
    }

    printf("Enter right node value for %d - ", current->data);
    scanf("%d", &x);

    if (x != -1) {
      temp = (struct Node *)malloc(sizeof(struct Node *));
      temp->data = x;

      current->rChild = temp;
      temp->lChild = nullptr;
      temp->rChild = nullptr;

      q.emplace(temp);
    }
  }
  return root;
}

void inorder(struct Node *root) {
  struct Node *current = root;

  if (current == nullptr) {
    return;
  }
  stack<struct Node *> s;

  while (current != nullptr || !s.empty()) {
    while (current != nullptr) {
      s.emplace(current);
      current = current->lChild;
    }

    current = s.top();
    s.pop();

    printf("%d ", current->data);
    current = current->rChild;
  }
}

void preOrder(struct Node *root) {
  struct Node *curr = root;

  if (curr == nullptr) {
    return;
  }

  stack<struct Node *> s;

  s.emplace(root);

  while (!s.empty()) {
    curr = s.top();
    s.pop();

    printf("%d ", curr->data);

    if (curr->rChild != nullptr) {
      s.emplace(curr->rChild);
    }

    if (curr->lChild != nullptr) {
      s.emplace(curr->lChild);
    }
  }
}

void postOrder(struct Node *root) {
  struct Node *curr = root;

  if (root == nullptr) {
    return;
  }

  stack<struct Node *> s1;
  stack<struct Node *> s2;

  s1.emplace(root);

  while (!s1.empty()) {
    curr = s1.top();
    s1.pop();

    s2.push(curr);

    if (curr->lChild != nullptr) {
      s1.push(curr->lChild);
    }

    if (curr->rChild != nullptr) {
      s2.push(curr->rChild);
    }
  }

  while (!s2.empty()) {
    curr = s2.top();
    s2.pop();

    printf("%d ", curr->data);
  }
}

int main() {
  struct Node *root = createBinaryTree();

  printf("Preorder\n");
  preOrder(root);
  printf("\n");

  printf("Inorder\n");
  inorder(root);
  printf("\n");

  printf("Postorder\n");
  postOrder(root);
  printf("\n");

  return 0;
}
