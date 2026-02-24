#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *link;
};

void enqueue(struct Node **head, int data) {
  struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
  struct Node *current = *head;
  temp->data = data;
  temp->link = NULL;

  if (*head == NULL) {
    *head = temp;
    return;
  }

  while (current->link != NULL) {
    current = current->link;
  }
  current->link = temp;
}

int dequeue(struct Node **head) {
  struct Node *current = NULL;
  if (*head == NULL) {
    printf("Queue Underflow!");
    return -1;
  }
  current = *head;
  int returnData = (*head)->data;
  *head = current->link;
  free(current);

  return returnData;
}

void printData(struct Node *head) {
  struct Node *current = head;
  while (current != NULL) {
    printf("%d\n", current->data);
    current = current->link;
  }
}

int main() {
  int n;
  printf("Enter number of elements in queue - ");
  scanf("%d", &n);

  struct Node *head = NULL;
  for (int i = 0; i < n; i++) {
    int data;
    printf("Enter data - ");
    scanf("%d", &data);

    enqueue(&head, data);
  }

  printData(head);

  int removeData;
  printf("Enter number of elements to remove - ");
  scanf("%d", &removeData);

  for (int i = 0; i < removeData; i++) {
    int popped = dequeue(&head);
    printf("Popped data - %d\n", popped);
  }

  printf("Changed data = \n");
  printData(head);
}
