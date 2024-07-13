#include <iostream>
using namespace std;

int T(int n) {
	return (n * (n + 1)) / 2;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int sum = 0;
		for (int i = 1; i <= n; i++) {
			sum += i * T(i + 1);
		}
		cout << sum << endl;
	}
}