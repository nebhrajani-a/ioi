#include <bits/stdc++.h>

int main(void)
{
  int c, r, d;
  std::cin >> r;
  std::cin >> c;
  std::cin >> d;

  int a[r][c];
  int fromleft[r][c];
  int fromtop[r][c];


  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      std::cin >> a[i][j];
    }
  }

  memset(fromtop, 0, sizeof(fromtop));
  memset(fromleft, 0, sizeof(fromleft));

  fromtop[0][0] = 1;
  fromleft[0][0] = 1;

  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      if (a[i][j]) {
        for (int t = 1; i + t < r && t <= d && a[i + t][j]; ++t) {
          fromtop[i + t][j] += fromleft[i][j];
          fromtop[i + t][j] %= 20011;
        }
        for (int t = 1; j + t < c && t <= d && a[i][j + t]; ++t) {
          fromleft[i][j + t] += fromtop[i][j];
          fromleft[i][j + t] %= 20011;
        }
      }
    }
  }

  std::cout << (fromtop[r-1][c-1] + fromleft[r-1][c-1]) % 20011 << "\n";
  return 0;
}
