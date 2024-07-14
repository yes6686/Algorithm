#include <iostream>
using namespace std;

int solve(int n) {
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		ans += (2 * i - 1);
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	while (T--) {
		int a, b;
		cin >> a >> b;
		cout << solve(a / b) << '\n';
	}
}