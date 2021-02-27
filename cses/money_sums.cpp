#include <bits/stdc++.h>

int main(void)
{
  int n;
  std::cin >> n;
  std::vector<int> v (n);
  std::vector<int> all;

  for (int i = 0; i < n; ++i) {
    std::cin >> v[i];
  }

  std::set<int> s;

  for (int i = 0; i < v.size(); ++i) {
    all.push_back(v[i]);
    unsigned int tmp = all.size() - 1;
    for (int j = 0; j < tmp; ++j) {
      all.push_back(v[i] + all[j]);
    }
    for (int j = 0; j < all.size(); ++j) {
      s.insert(all[j]);
    }
    all.clear();

    std::set<int>::iterator itr;
    for (itr = s.begin(); itr != s.end(); ++itr) {
      all.push_back(*itr);
    }
    all.shrink_to_fit();
  }


  // for (int i = 0; i < all.size(); ++i) {
  //   s.insert(all[i]);
  // }

  std::cout << s.size() << "\n";

  std::set<int>::iterator itr;
  for (itr = s.begin(); itr != s.end(); ++itr) {
    std::cout << *itr << " ";
  }
  std::cout << "\n";

  return 0;
}
