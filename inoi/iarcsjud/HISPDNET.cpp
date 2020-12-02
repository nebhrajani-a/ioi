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
  int N;
  std::cin >> N;
  int r = N-2;
  std::string str;
  getline(std::cin, str);
  // std::vector<int> g = {4,5,6};
  // std::vector<std::vector<int>> q (N);
  std::vector<int> a;

  getline(std::cin,str);
  for (int i = 1; i < N-1; ++i) {
    getline(std::cin,str);
    int iter = 0;
    int b = 0;
    for (int i = str.size() - 1; i >= 0; i--) {
      if (str[i] == ' ') {
        if (b == 0) {
          break;
        }
        a.insert(a.begin(), b);
        b = 0;
        iter = 0;
        i--;
      }
      if (i == 0) {
        int p = str[i] - 48;
        b += (std::pow(10, iter))*p;
        if (b == 0) {
          break;
        }
        a.insert(a.begin(), b);
      }
      int p = str[i] - 48;
      b += (std::pow(10, iter))*p;
      iter++;
    }
  }

  // for (int i = 0; i < a.size(); ++i) {
  //   std::cout << a[i] << " ";
  // }
  // std::cout << "\n";


  std::vector<int> data (r);
  combinations(a, data, 0, a.size(), 0, r);
  std::cout << minimum << "\n";

  return 0;
}
