#include <bits/stdc++.h>

int main(void)
{
  int n, k;
  std::cin >> n;
  std::cin >> k;

  std::vector<int> forw (n+1);
  std::vector<int> backw (n+1);
  std::vector<int> arr (n+1);

  for (int i = 1; i <= n; ++i) {
    std::cin >> arr[i];
  }

  for (int i = k+1; i <= n; ++i) {
    forw[i] = arr[i] + std::max(forw[i-1], forw[i-2]);
  }

  backw[1] = arr[1];
  backw[2] = arr[1] + arr[2];
  for (int i = 3; i <= n; ++i) {
    backw[i] = arr[i] + std::max(backw[i-1], backw[i-2]);
  }

  int ans = backw[k] - arr[k];

  for (int i = k+1; i <= n; ++i) {
    ans = std::max(ans, forw[i] + backw[i] - arr[i]);
  }

  std::cout << ans << "\n";

  return 0;
}
