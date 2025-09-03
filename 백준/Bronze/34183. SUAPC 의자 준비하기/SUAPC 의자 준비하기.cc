#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, a, b;
	cin >> n >> m >> a >> b;

	if (n * 3 <= m) {
		cout << 0 << '\n';
	}
	else {
		cout << ((n * 3) - m) * a + b;
	}
}