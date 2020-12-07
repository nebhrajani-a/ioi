#include <bits/stdc++.h>

int fib(int x)
{
  std::vector<int> fibtable (x+1);
  fibtable[0] = 0;
  fibtable[1] = 1;
  for (int i = 2; i <= x; ++i) {
    fibtable[i] = fibtable[i-1] + fibtable[i-2];
  }
  return fibtable[x];
}

int main()
{
  std::cout << fib(7) << "\n";
  return 0;
}
