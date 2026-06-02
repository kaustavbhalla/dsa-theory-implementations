#include <stdio.h>
#include <stdlib.h>
struct Node {
  int data;
  struct Node *link;
};

void addNodeToEnd(struct Node **head, int data) {
  struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
  temp->data = data;
  temp->link = NULL;

  if (*head == NULL) {
    *head = temp;
    return;
  }

  struct Node *curr = *head;
  while (curr->link != NULL) {
    curr = curr->link;
  }

  curr->link = temp;
}

void reverseLinkedList(struct Node **head) {
  struct Node *curr = *head;
  struct Node *prev = NULL;
  struct Node *next = NULL;
  while (curr->link != NULL) {
    next = curr->link;
    curr->link = prev;

    prev = curr;
    curr = next;
  }
  *head = prev;
}
