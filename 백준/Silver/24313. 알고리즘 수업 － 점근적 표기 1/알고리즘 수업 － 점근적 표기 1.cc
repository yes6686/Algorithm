#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int a1, a0;
	cin >> a1 >> a0;
	int c;
	cin >> c;
	int n0;
	cin >> n0;
	if (a1 > c) {
		cout << 0 << '\n';
	}
	else if (a1 <= c) {
		if (a1 * n0 + a0 <= c * n0) {
			cout << 1 << '\n';
		}
		else {
			cout << 0 << '\n';
		}
	}
}