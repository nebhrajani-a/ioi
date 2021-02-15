#include <iostream>
#include <vector>

# define FASTER ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)

using namespace std;

int main() {
	FASTER;
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
	#endif

	int n;
	cin >> n;
	vector<int> a(n);

	cin >> a[0];
	int score = a[0] + n;
	for (int i = 1; i < n; ++i) {
		cin >> a[i];
		score = max(score, a[i] + i);
	}

	vector<int> scores(n + 1);
	scores[n] = score;

	for (int k = n - 1; k >= 1; --k)
		scores[k] = max(scores[k + 1]-1, a[n-k] + n);

	for (int k = 1; k <= n; ++k)
		cout << scores[k] << ' ';

	return 0;
}
