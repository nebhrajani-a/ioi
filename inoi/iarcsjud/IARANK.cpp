#include<bits/stdc++.h>

int insert_at(std::vector<int> a, int n)
{
  for (int i = 0; i < a.size(); ++i) {
    if (n >= a[i]) {
      return i;
    }
  }
  return a.size();
}

int main()
{

  int N;
  std::cin >> N;
  std::vector<int> og;

  for (int i = 0; i < N; ++i) {
    int a;
    std::cin >> a;
    int x =  insert_at(og, a);
    og.insert(og.begin() + x, a);
    std::cout << x+1 << "\n";
  }
  return 0;
}
