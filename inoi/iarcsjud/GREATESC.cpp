#include<bits/stdc++.h>
using namespace std;
# define INF 0x3f3f3f3f

void add_edge(std::vector<std::list<std::pair<int,int>>>& graph, int u, int v)
{
  graph[u].push_back(make_pair(v, 1));
  graph[v].push_back(make_pair(u, 1));
}

int shortest_path(std::vector<std::list<std::pair<int,int>>>& graph, int src, int dest, int V)
{
  set<pair<int,int>> setds;
  vector<int> dist(V, INF);
  setds.insert(make_pair(0, src));
  dist[src] = 0;

  while (!setds.empty()) {
    pair<int,int> tmp = *(setds.begin());
    setds.erase(setds.begin());
    int u = tmp.second;
    list<pair<int,int>>::iterator i;
    for (i = graph[u].begin(); i != graph[u].end(); ++i) {
      int v = (*i).first;
      int weight = (*i).second;
      if (dist[v] > dist[u] + weight) {
        if (dist[v] != INF) {
          setds.erase(setds.find(make_pair(dist[v], v)));
        }
        dist[v] = dist[u] + weight;
        setds.insert(make_pair(dist[v], v));
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
  cin >> V >> N;
  std::vector<std::list<std::pair<int,int>>> g (V);

  for (int i = 0; i < N; ++i) {
    cin >> a >> b;

    add_edge(g, a-1, b-1);
  }

  cin >> a >> b;
  int x = shortest_path(g, (a-1), (b-1), V);
  if (x == INF) {
    x = 0;
  }
  cout << x << "\n";

  return 0;
}
