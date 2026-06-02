#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *leftChild;
  struct Node *rightChild;
};

struct Node *createBinaryTree() {
  struct Node *root = (struct Node *)malloc(sizeof(struct Node));
  printf("Enter data at root - ");
  scanf("%d", &(root->data));

  root->leftChild = NULL;
  root->rightChild = NULL;

  int n;
  printf("Enter number of elements to add - ");
  scanf("%d", &n);

  struct Node *curr = root;

  while (n--) {

    printf("Enter left child for %d - ", curr->data);
    int l;
    scanf("%d", &l);

    if (l != -1) {
      struct Node *left = (struct Node *)malloc(sizeof(struct Node));
      left->data = l;
      left->leftChild = NULL;
      left->rightChild = NULL;

      curr->leftChild = left;
    }

    printf("Enter right child for %d - ", curr->data);
    int r;
    scanf("%d", &r);

    if (r != -1) {
      struct Node *right = (struct Node *)malloc(sizeof(struct Node));
      right->data = l;
      right->leftChild = NULL;
      right->rightChild = NULL;

      curr->rightChild = right;
    }

    curr = curr->leftChild;
  }

  while (n--) {

    printf("Enter left child for %d - ", curr->data);
    int l;
    scanf("%d", &l);

    if (l != -1) {
      struct Node *left = (struct Node *)malloc(sizeof(struct Node));
      left->data = l;
      left->leftChild = NULL;
      left->rightChild = NULL;

      curr->leftChild = left;
    }

    printf("Enter right child for %d - ", curr->data);
    int r;
    scanf("%d", &r);

    if (r != -1) {
      struct Node *right = (struct Node *)malloc(sizeof(struct Node));
      right->data = l;
      right->leftChild = NULL;
      right->rightChild = NULL;

      curr->rightChild = right;
    }

    curr = curr->rightChild;
  }

  return root;
}
