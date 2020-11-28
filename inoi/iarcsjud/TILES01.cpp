#include <bits/stdc++.h>
using namespace std;
# define ll long long

int main()
{
  ll N;
  cin >> N;
  ll a = 1;
  ll b = 1;
  ll sum = 0;
  for (ll i = 0; i < N-1; ++i) {
    sum = a+b % 15746;
    a = b;
    b = sum;
  }
  ll result = sum % 15746;
  cout << result << "\n";

  return 0;
}
