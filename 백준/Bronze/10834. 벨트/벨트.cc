#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int m;
	cin >> m;
	int d = 0;
	int r = 1;
	for (int i = 1; i <= m; i++) {
		int a, b, s;
		cin >> a >> b >> s;
		r *= b;
		r /= a;
		if (s == 1) {
			d = d == 0 ? 1 : 0;
		}
	}
	cout << d << " " << r;
}