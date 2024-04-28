#include <iostream>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long long int k, n;
	cin >> k >> n;
	if (n == 1) {
		cout << -1;
		return 0;
	}
	long long int ans = k;
	while (1) {
		long long int v = (ans - k) * n;
		if (v >= ans) {
			cout << ans;
			break;
		}
		ans++;
	}
}