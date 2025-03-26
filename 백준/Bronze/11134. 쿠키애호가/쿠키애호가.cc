#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);


	int T;
	cin >> T;
	while (T--) {
		int n, c;
		cin >> n >> c;
		if (n % c == 0) {
			cout << n / c << '\n';
		}
		else {
			cout << n / c + 1 << '\n';
		}

	}
}