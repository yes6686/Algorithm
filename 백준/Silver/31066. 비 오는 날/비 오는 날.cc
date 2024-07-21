#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	while (T--) {
		int n, m, k;
		cin >> n >> m >> k;
		if (n > 1 && m == 1 && k == 1) {
			cout << -1 << '\n';
			continue;
		}
		int cnt = 0;
		int a = n, b = m, c = 0, d = 0;		
		while (true) {
			if (c == n) break;
			if (b == 0) {
				b = d;
				d = 0;
				c -= 1;
				a += 1;
			}
			else if (a >= b * k) {
				a -= b * k;
				d = b;
				c += b * k;
				b = 0;
			}
			else {
				c = n;
			}
			cnt++;
		}
		cout << cnt << '\n';
	}
}