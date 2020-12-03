// DFS: the 'stack' is maintained as recursive function calls implicitly.

#include <bits/stdc++.h>

void dfs(std::vector<std::vector<int>>& g, std::vector<int>& visited, std::vector<int>& parent, int src)
{
  visited[src] = 1;
  for (int i = 0; i < g[src].size(); ++i) {
    if (visited[g[src][i]] == 0) {
      parent[g[src][i]] = src;
      dfs(g, visited, parent, g[src][i]);
    }
  }
}

void add_edge(std::vector<std::vector<int>>& g, int a, int b)
{
  g[a].push_back(b);
  g[b].push_back(a);
}

int main()
{
  int V = 10;
  std::vector<std::vector<int>> g (V);
  std::vector<int> visited (V);
  std::vector<int> parent (V);

  add_edge(g,0,1);
  add_edge(g,0,2);
  add_edge(g,1,2);
  add_edge(g,0,3);
  add_edge(g,3,4);
  add_edge(g,3,7);
  add_edge(g,4,5);
  add_edge(g,5,7);
  add_edge(g,5,6);
  add_edge(g,5,8);
  add_edge(g,7,8);
  add_edge(g,8,9);

  dfs(g,visited,parent,0);
  std::cout << visited[9] << "\n";
  return 0;
}
