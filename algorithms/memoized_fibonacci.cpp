#include <bits/stdc++.h>

int fib(std::vector<int>& fibtable, int n)
{
  int value;
  if (fibtable[n] != 0) {
    return fibtable[n];
  }
  if (n == 0 || n == 1) {
    value = n;
  }
  else {
    value = fib(fibtable, n-1) + fib(fibtable, n-2);
  }
  fibtable[n] = value;

  return value;
}

int main()
{
  int n = 7;
  std::vector<int> fibtable (n+1);
  std::cout << fib(fibtable, n) << "\n";

  return 0;
}
