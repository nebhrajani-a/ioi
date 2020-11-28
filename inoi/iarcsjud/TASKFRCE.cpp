#include<bits/stdc++.h>

void add_edge(std::vector<std::vector<int>>& g, int a, int b)
{
  g[a-1].push_back(b);
  g[b-1].push_back(a);
}

int main()
{
  int V;
  int Q;
  int N;
  std::cin >> V >> Q >> N;
  std::vector<std::vector<int>> g (V);
  std::vector<int> q;

  for (int i = 0; i < Q; ++i) {
    int a, b;
    std::cin >> a >> b;
    add_edge(g, a, b);
  }


  for (int i = 0; i < V; ++i) {
    if (g[i].size() < N) {
      q.push_back(i+1);
    }
  }

  for (int j = 0; j < q.size(); ++j) {
    int x = q[j] - 1;
    for (int i = 0; i < g[x].size(); ++i) {
      auto pos = std::find(std::begin(g[g[x][i]-1]), std::end(g[g[x][i]-1]), x+1);
      if (pos != std::end(g[g[x][i]-1])) {
        g[g[x][i]-1].erase(pos);
        if (g[g[x][i]-1].size() < N) {
          q.push_back(g[x][i]);
        }
      }
    }
  }


  int count = 0;
  for (int i = 0; i < V; ++i) {
    if (g[i].size() >= N) {
      count++;
    }
  }

  if (count == 0) {
    std::cout << "NO" << "\n";
  }

  else {
    std::cout << "YES" << "\n";
    std::cout << count << "\n";
  }

  return 0;
}
