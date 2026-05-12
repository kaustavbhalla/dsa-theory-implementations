#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXI 100

struct Node {
  int vertex;
  struct Node *link;
};

struct Node *adj[MAXI];

void addEdge(int u, int v) {
  struct Node *curr = (struct Node *)malloc(sizeof(struct Node));
  curr->vertex = v;
  curr->link = adj[u];
  adj[u] = curr;

  struct Node *curr2 = (struct Node *)malloc(sizeof(struct Node));
  curr2->vertex = u;
  curr->link = adj[v];
  adj[v] = curr2;
}

void dfsHelper(int node, int visited[]) {
  visited[node] = 1;

  printf("%d ", node);

  struct Node *curr = adj[node];

  while (curr != NULL) {
    if (!visited[curr->vertex]) {
      dfsHelper(curr->vertex, visited);
    }
    curr = curr->link;
  }
}

void dfs(int start) {
  int visited[MAXI];
  memset(visited, 0, sizeof(visited));

  dfsHelper(start, visited);
}
