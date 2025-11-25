#include <iostream>
using namespace std;

int main() {
	int T;
	cin >> T;
	while (T--) {
		int n, k;
		cin >> n >> k;
		int ans = 0;
		for (int i = 0;i < n;i++) {
			int x;
			cin >> x;
			ans += x / k;
		}
		cout << ans << '\n';
	}
}