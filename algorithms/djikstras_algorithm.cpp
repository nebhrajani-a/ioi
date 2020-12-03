#include <bits/stdc++.h>

struct node
{
  int dest;
  int weight;
};

void add_edge(std::vector<std::vector<node>>& g, int src, int dest, int weight)
{
  g[src].push_back({dest, weight});
  g[dest].push_back({src, weight});
}

void djikstra(std::vector<std::vector<node>>& g, std::vector<int>& distance, int src)
{
  std::vector<bool> visited (g.size());
  distance[src] = 0;

  for (int i = 0; i < g.size(); ++i) {
    int min = std::numeric_limits<int>::max();
    int u;
    for (int j = 0; j < visited.size(); ++j) {
      if (!visited[j]) {
        if (distance[j] < min) {
          min = distance[j];
          u = j;
        }
      }
    }
    visited[u] = true;
    for (int k = 0; k < g[u].size(); ++k) {
      if (!visited[g[u][k].dest] && distance[g[u][k].dest] > distance[u] + g[u][k].weight) {
        distance[g[u][k].dest] = distance[u] + g[u][k].weight;
      }
    }
  }
}

int main()
{
  int V = 7;
  std::vector<std::vector<node>> g (V);
  add_edge(g,0,2,80);
  add_edge(g,0,1,10);
  add_edge(g,1,2,6);
  add_edge(g,2,3,70);
  add_edge(g,1,4,20);
  add_edge(g,4,6,10);
  add_edge(g,4,5,50);
  add_edge(g,5,6,5);
  std::vector<int> distance (V, std::numeric_limits<int>::max());

  djikstra(g, distance, 0);
  for (int x: distance) {
    std::cout << x << "\n";
  }

  return 0;
}
