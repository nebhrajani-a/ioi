#include <bits/stdc++.h>

struct pair
{
  int first;
  int second;
};


void seq_checker(std::vector<std::vector<int>>& g, std::vector<int> p, int j, int i)
{

}

int main()
{
  // int N;
  // std::cin >> N;
  // std::vector<int> a;
  // std::string str;
  // getline(std::cin,str);
  // int iter = 0;
  // int b = 0;
  // for (int i = str.size() - 1; i >= 0; i--) {
  //   if (str[i] == ' ') {
  //     a.insert(a.begin(), b);
  //     b = 0;
  //     iter = 0;
  //     i--;
  //   }
  //   if (i == 0) {
  //     int p = str[i] - 48;
  //     b += (std::pow(10, iter))*p;
  //     a.insert(a.begin(), b);
  //   }
  //   int p = str[i] - 48;
  //   b += (std::pow(10, iter))*p;
  //   iter++;
  // }

  // for (int x: a) {
  //   std::cout << x << "\n";
  // }

  std::vector<std::vector<int>> g = {{4,2}, {5}, {2,1}, {2,5,3}, {3,1}};

  for (int i = 0; i < g.size(); ++i) {
    auto x = g[i];
    std::cout << i +1 << ": ";
    for (auto y: x) {
      std::cout << y << "->";
    }
    std::cout << "NULL" << "\n";
  }

  // std::vector<pair> q;

  // for (int j = 0; j < g.size(); ++j) {
  //   for (int i = 0; i < g[j].size(); ++i) {
  //     q.push_back({j+1, g[j][i]});
  //   }
  // }

  // std::vector<int> res;
  std::vector<int> p = {1,2,3,4,5};
  seq_checker(g, p);

  return 0;
}
