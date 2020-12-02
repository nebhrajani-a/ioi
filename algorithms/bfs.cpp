// BFS to check if two nodes are connected, and can calculate shortest path
// where edge weights are 1, using the 'parent' vector and backtracking how we
// got there.
#include <bits/stdc++.h>

bool bfs(std::vector<std::vector<int>>& g, int src, int dest)
{
  std::vector<int> visited (g.size());
  // std::vector<int> parent (g.size());
  std::deque<int> q;

  visited[src] = 1;
  q.push_back(src);

  while (q.size() != 0) {
    int j = q[0];
    for (int i = 0; i < g[j].size(); ++i) {
      if (visited[g[j][i]] == 0) {
        visited[g[j][i]] = 1;
        // parent[g[j][i]] = j;
        q.push_back(g[j][i]);
      }
    }
    q.pop_front();
  }
  // for (auto x: parent) {
  //       std::cout << x << "\n";
  // }


  if (visited[dest] == 1) {
    return true;
  }
  else {
    return false;
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

  if (bfs(g,0,9)) {
    std::cout << "True" << "\n";
  }
  else {
    std::cout << "False" << "\n";
  }

  return 0;
}
