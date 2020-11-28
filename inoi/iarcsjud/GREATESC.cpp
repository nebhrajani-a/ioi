#include<bits/stdc++.h>

# define INF 0x3f3f3f3f

void add_edge(std::vector<std::list<std::pair<int,int>>>& graph, int u, int v)
{
  graph[u].push_back(std::make_pair(v, 1));
  graph[v].push_back(std::make_pair(u, 1));
}

int shortest_path(std::vector<std::list<std::pair<int,int>>>& graph, int src, int dest, int V)
{
  std::set<std::pair<int,int>> setds;
  std::vector<int> dist(V, INF);
  setds.insert(std::make_pair(0, src));
  dist[src] = 0;

  while (!setds.empty()) {
    std::pair<int,int> tmp = *(setds.begin());
    setds.erase(setds.begin());
    int u = tmp.second;
    std::list<std::pair<int,int>>::iterator i;
    for (i = graph[u].begin(); i != graph[u].end(); ++i) {
      int v = (*i).first;
      int weight = (*i).second;
      if (dist[v] > dist[u] + weight) {
        if (dist[v] != INF) {
          setds.erase(setds.find(std::make_pair(dist[v], v)));
        }
        dist[v] = dist[u] + weight;
        setds.insert(std::make_pair(dist[v], v));
      }
    }
  }
  return dist[dest];
}

int main()
{
  int V;
  int N;
  int a;
  int b;
  std::cin >> V >> N;
  std::vector<std::list<std::pair<int,int>>> g (V);

  for (int i = 0; i < N; ++i) {
    std::cin >> a >> b;

    add_edge(g, a-1, b-1);
  }

  std::cin >> a >> b;
  int x = shortest_path(g, (a-1), (b-1), V);
  if (x == INF) {
    x = 0;
  }
  std::cout << x << "\n";

  return 0;
}
