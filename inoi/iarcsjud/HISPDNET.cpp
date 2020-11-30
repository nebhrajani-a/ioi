#include <bits/stdc++.h>
# define INF 0x3f3f3f3f

int minimum = INF;

void combinations(std::vector<int> arr, std::vector<int> data, int start, int end, int index, int r)
{
  if (index == r) {
    int sum = 0;
    for (int j = 0; j < r; j++) {
      // std::cout << data[j] << " ";
      sum += data[j];
    }
    if (sum < minimum) {
      minimum = sum;
    }
    // std::cout << sum << "\n";
    return;
  }
  for (int i = start; i < end && end - i +1 >= r; ++i) {
    data[index] = arr[i];
    combinations(arr, data, i+1, end, index+1, r);
  }
}

int main()
{
  int N = 4;
  // std::cin >> N;
  int r = N-2;
  std::vector<int> g = {4,5,6};

  std::vector<int> data (r);
  combinations(g, data, 0, g.size(), 0, r);
  std::cout << minimum << "\n";

  return 0;
}
