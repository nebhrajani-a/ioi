#include <bits/stdc++.h>

void add_edge(std::vector<std::vector<int>>& g, int src, int dest)
{
  g[src].push_back(dest);
}

void sort(std::vector<std::vector<int>>& g, std::vector<int>& sorted)
{
  std::vector<int> indegree (g.size());
  std::deque<int> q;

  for (int i = 0; i < g.size(); ++i) {
    for (int j = 0; j < g[i].size(); ++j) {
      indegree[g[i][j]]++;
    }
  }

  for (int i = 0; i < indegree.size(); ++i) {
    if (indegree[i] == 0) {
      q.push_back(i);
    }
  }

  while (q.size() != 0) {
    int j = q[0];
    q.pop_front();
  }
}

int main()
{
  int V = 8;
  std::vector<std::vector<int>> g (V);
  add_edge(g,0,2);
  add_edge(g,0,3);
  add_edge(g,0,4);
  add_edge(g,1,2);
  add_edge(g,1,7);
  add_edge(g,2,5);
  add_edge(g,3,5);
  add_edge(g,3,7);
  add_edge(g,4,7);
  add_edge(g,5,6);
  add_edge(g,6,7);

  std::vector<int> sorted (V);
  sort(g, sorted);

  return 0;
}
