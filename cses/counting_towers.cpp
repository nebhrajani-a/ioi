#include <bits/stdc++.h>

long int dp[1000001][2];
int main(void)
{
  dp[1][1] = dp[1][0] = 1;
  for (int i = 2; i < 1000001; ++i) {
    dp[i][0] = ((dp[i-1][0] * 4) + dp[i-1][1]) % 1000000007;
    dp[i][1] = ((dp[i-1][1] * 2) + dp[i-1][0]) % 1000000007;
  }

  int t;
  std::cin >> t;
  while (t--) {
    int n;
    std::cin >> n;
    std::cout << (dp[n][0] + dp[n][1]) % 1000000007 << "\n";
  }
  return 0;
}
