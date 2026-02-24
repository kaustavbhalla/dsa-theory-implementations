#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *link;
};

void addAtEnd(struct Node **head, int data) {
  struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
  temp->data = data;
  temp->link = NULL;

  if (*head == NULL) {
    *head = temp;
    return;
  }

  struct Node *current = (struct Node *)malloc(sizeof(struct Node));
  current = *head;

  while (current->link != NULL) {
    current = current->link;
  }

  current->link = temp;
}

void printList(struct Node *head) {
  struct Node *current = NULL;
  current = head;

  while (current != NULL) {
    printf("Data: %d\n", current->data);
    current = current->link;
  }
}

int main() {
  struct Node *head = NULL;
  addAtEnd(&head, 1);
  addAtEnd(&head, 2);

  printList(head);
}
