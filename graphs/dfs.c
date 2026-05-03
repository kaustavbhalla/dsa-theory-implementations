#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXI 100

struct Node {
  int val;
  struct Node *link;
};

struct Node *adj[MAXI];
int n;

void addEdge(int u, int v) {
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->val = v;
  newNode->link = adj[u];
  adj[u] = newNode;

  struct Node *newNode2 = (struct Node *)malloc(sizeof(struct Node));
  newNode2->val = u;
  newNode2->link = adj[v];
  adj[v] = newNode2;
}

void dfsHelper(int node, int visited[]) {
  visited[node] = 1;

  printf("%d ", node);

  struct Node *curr = adj[node];

  while (curr != NULL) {
    if (!visited[curr->val]) {
      dfsHelper(curr->val, visited);
    }
    curr = curr->link;
  }
}

void dfs(int start) {
  int visited[MAXI];
  memset(visited, 0, sizeof(visited));

  dfsHelper(start, visited);
  printf("\n");
}

int main() {
  n = 6;
  memset(adj, 0, sizeof(adj));

  addEdge(0, 1);
  addEdge(0, 2);
  addEdge(1, 3);
  addEdge(1, 4);
  addEdge(2, 5);

  printf("Recursive DFS from 0: ");
  dfs(0);
}
