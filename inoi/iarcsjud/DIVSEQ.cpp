#include <bits/stdc++.h>
using namespace std;

int main()
{
  int arr[] = //{2,3,7,8,14,39,145,76,320};
    {2,11,16,12,36,60,71,17,29,144,288,129,432,993};
  int N = 14;
  int count = 0;
  int final_count = 0;
  std::vector<std::vector<int>> q (N);
  int i;
  int j;


  for (j = 0; j < N; ++j) {
    for (i = j+1; i < N; i++) {
      if (arr[i] % arr[j] == 0) {
        q[j].push_back(i);
      }
    }
  }

  for (i = 0; i < N; ++i) {
    cout << i << " is: ";
    for (int x: q[i]) {
      cout << x << " -> ";
    }
    cout << "NULL" << "\n";
  }
  return 0;
}
