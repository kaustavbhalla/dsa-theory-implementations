#include <bits/stdc++.h>
#include <cstddef>
#define MAXI 100
using namespace std;

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

void bfs(int node, vector<bool> &visited) {
  queue<int> q;
  visited[node] = true;

  printf("%d ", node);

  struct Node *curr = adj[node];
  q.emplace(node);

  while (!q.empty()) {
    node = q.front();
    q.pop();

    curr = adj[node];

    while (curr != NULL) {
      if (!visited[curr->val]) {
        printf("%d ", curr->val);
        q.emplace(curr->val);
        visited[curr->val] = true;
      }

      curr = curr->link;
    }
  }
}
