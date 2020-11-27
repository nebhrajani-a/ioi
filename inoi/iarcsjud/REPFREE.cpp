#include<bits/stdc++.h>
using namespace std;

// Very naive algo

int unique_checker(int N) {
  std::string s = std::to_string(N);
  std::set<char> st;
  for (int i = 0; i < s.size(); ++i) {
    st.insert(s[i]);
  }
  if (s.size() == st.size() && st.find('0') == st.end())
    return 0;
  return 1;
}

int main()
{
  int N;
  cin >> N;
  int result;
  while (N < 987654321) {
    N++;
    result = unique_checker(N);
    if (result == 0)
      break;
  }
  if (N >= 987654321) {
    N = 0;
  }

  cout << N << "\n";

  return 0;
}
