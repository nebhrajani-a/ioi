// To search a sorted array for a value.
#include <bits/stdc++.h>

int binary_search(std::vector<int>& a, int k, int l, int r)
{
  if (r >= l) {
    int mid = (l+r)/2;
    if (k == a[mid]) {
      return mid;
    }
    if (a[mid] < k) {
      return binary_search(a, k, mid+1, r);
    }
    if (a[mid] > k) {
      return binary_search(a, k, l, mid-1);
    }
  }
  return -1;
}

int main()
{
  std::vector<int> arr = {34,54,23,35,13,35,46,678,34,576,46,34,646};
  std::sort(std::begin(arr), std::end(arr));
  int find = binary_search(arr, 46, 0, arr.size());
  std::cout << arr[find] << "\n";
  return 0;
}
