#include <bits/stdc++.h>
using namespace std;

#define INF INT_MAX
int n;
vector<pair<int, int>> adj[100]; // {neighbour, weight}

void addEdge(int u, int v, int w) {
  adj[u].push_back({v, w});
  adj[v].push_back({u, w});
}

void dijkstra(int start) {
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      pq; // {distance, vertex}

  vector<int> dist(n, INF);
  vector<int> parent(n, -1);

  dist[start] = 0;
  pq.push({0, start});

  while (!pq.empty()) {
    auto [d, u] = pq.top();
    pq.pop();

    if (d > dist[u]) {
      continue;
    }

    for (auto [v, w] : adj[u]) {
      if (w + dist[u] < dist[v]) {
        dist[v] = w + dist[u];
        parent[v] = u;
        pq.push({dist[v], v});
      }
    }
  }
}
