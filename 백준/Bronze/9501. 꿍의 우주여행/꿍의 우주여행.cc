#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	while (T--) {
		int n, d;
		cin >> n >> d;
		int ans = 0;
		for (int i = 0; i < n; i++) {
			int v, f, c;
			cin >> v >> f >> c;
			if ((v * f) / c >= d) {
				ans++;
			}
		}
		cout << ans << '\n';
	}
}