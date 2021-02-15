#include <bits/stdc++.h>

typedef struct citizen
{
  int id;
  int sum;
} citizen;

bool comparator(citizen a, citizen b)
{
  return a.sum > b.sum;
}

int main(void)
{
  int n;
  std::cin >> n;

  std::vector<citizen> cvec(n);

  for (int i = 0; i < n; ++i) {
    int a, b, c;
    std::cin >> a >> b >> c;
    cvec[i] = {a, b+c};
  }

  std::sort(cvec.begin(), cvec.end(), comparator);

  int max = std::numeric_limits<int>::min();
  int total = 0;
  for (int i = 0; i < n; ++i) {
    total += cvec[i].id;
    if (max < total+cvec[i].sum) {
      max = total+cvec[i].sum;
    }
  }

  std::cout << max << "\n";

  return 0;
}
