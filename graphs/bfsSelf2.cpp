#include <bits/stdc++.h>
#include <cstddef>
#include <unistd.h>
using namespace std;

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

void bfs(int node, int visited[]) {
  visited[node] = true;

  printf("%d ", node);

  queue<int> q;
  q.emplace(node);

  struct Node *curr;

  while (!q.empty()) {
    node = q.front();
    q.pop();

    curr = adj[node];

    while (curr != NULL) {
      if (!visited[curr->vertex]) {
        visited[curr->vertex] = true;
        printf("%d ", curr->vertex);
        q.emplace(curr->vertex);
      }

      curr = curr->link;
    }
  }
}
