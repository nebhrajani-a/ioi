#include <bits/stdc++.h>

struct node
{
  int dest;
  int weight;
};

void add_edge(std::vector<std::vector<node>>& g, int src, int dest, int weight)
{
  g[src].push_back({dest, weight});
}

void bellman(std::vector<std::vector<node>>& g, std::vector<int>& distance, int src)
{
  distance[src] = 0;

  for (int k = 0; k < g.size() - 1; ++k) {
    for (int i = 0; i < g.size(); ++i) {
      for (int j = 0; j < g[i].size(); ++j) {
        if (distance[i] != std::numeric_limits<int>::max()) {
          distance[g[i][j].dest] = std::min(distance[g[i][j].dest], distance[i] + g[i][j].weight);
        }
      }
    }
  }
}

int main()
{
  int V = 8;
  std::vector<std::vector<node>> g (V);
  add_edge(g,0,7,8);
  add_edge(g,0,1,10);
  add_edge(g,7,6,1);
  add_edge(g,6,5,-1);
  add_edge(g,6,1,-4);
  add_edge(g,1,5,2);
  add_edge(g,5,2,-2);
  add_edge(g,4,5,-1);
  add_edge(g,3,4,3);
  add_edge(g,2,3,1);
  add_edge(g,2,1,1);
  std::vector<int> distance (V, std::numeric_limits<int>::max());


  bellman(g, distance, 0);
  for (int x: distance) {
    std::cout << x << "\n";
  }

  return 0;
}
