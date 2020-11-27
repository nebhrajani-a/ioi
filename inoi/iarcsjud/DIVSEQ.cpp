#include <bits/stdc++.h>
using namespace std;

struct node
{
  int d;
  int color;
  int pi;
  int value;
};


int time_ = 0;

void dfs_visit(std::vector<std::vector<node>>& g, int u) {
  time_++;
  g[u][0].d = time_;
  g[u][0].color = 1;
  int i;
  for (i = 0; i < g[u].size(); ++i) {
    if (g[u][i].color == 0) {
      g[u][i].pi = g[u][0].value;
      dfs_visit(g, g[u][i].value);
    }
  }
  g[u][0].color = 2;
  time_++;
}

int main()
{
  std::vector<int> arr =// {2,3,7,8,14,39,145,76,320};
    {2,11,16,12,36,60,71,17,29,144,288,129,432,993};
  int N = arr.size();
  std::vector<std::vector<node*>> q (N);
  int i;
  int j;



  for (j = 0; j < N; ++j) {
      q[j].push_back({0,0,0,j});
    for (i = j+1; i < N; i++) {
      if (arr[i] % arr[j] == 0) {
        q[j].push_back();
      }
    }
  }


  for (i = 0; i < N; ++i) {
    cout << i << " is: ";
    for (node x: q[i]) {
      cout << x.value << " -> ";
    }
    cout << "NULL" << "\n";
  }

  for (i = 0; i < q.size(); ++i) {
    if (q[i][0].color == 0) {
      dfs_visit(q, i);
    }
  }

  for (i = 0; i < N; ++i) {
    cout << i << " is: ";
    for (node x: q[i]) {
      cout << x.color << " -> ";
    }
    cout << "NULL" << "\n";
  }


  return 0;
}
