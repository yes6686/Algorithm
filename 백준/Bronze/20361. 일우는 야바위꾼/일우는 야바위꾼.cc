#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, x, k;
	cin >> n >> x >> k;
	for (int i = 0; i < k; i++) {
		int a, b;
		cin >> a >> b;
		if (x == a) {
			x = b;
		}
		else if (x == b) {
			x = a;
		}
	}
	cout << x;
}