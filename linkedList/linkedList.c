#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *link;
};

struct Node *addAtEnd(struct Node **head, int data) {
  struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
  temp->data = data;
  temp->link = NULL;

  if (*head == NULL) {
    *head = temp;
    return *head;
  }

  struct Node *current = *head;

  while (current->link != NULL) {
    current = current->link;
  }
  current->link = temp;
  return current;
}

void printData(struct Node *head) {
  struct Node *current = head;
  int i = 0;
  while (current != NULL) {
    printf("Data at node %d - %d\n", i + 1, current->data);
    current = current->link;
    i++;
  }
}

struct Node *reversingLinkedList(struct Node **head) {
  struct Node *prev = NULL;
  struct Node *current = *head;
  struct Node *next = NULL;
  while (current != NULL) {
    next = current->link;
    current->link = prev;
    prev = current;
    current = next;
  }
  return prev;
}

int main() {
  struct Node *head = NULL;
  int n = 5;

  for (int i = 0; i < n; i++) {
    int data;
    printf("Enter data - ");
    scanf("%d", &data);
    struct Node *current = addAtEnd(&head, data);
  }

  printData(head);
  printf("\nReversed Link List\n");
  head = reversingLinkedList(&head);
  printData(head);
}
