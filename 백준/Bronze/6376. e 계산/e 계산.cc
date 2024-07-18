#include <iostream>
using namespace std;

double factorial(int n) {
	if (n <= 1) return 1;
	return n * factorial(n - 1);
}

double e(int n) {
	if (n == 0) return 1;
	return 1/factorial(n) + e(n - 1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cout << "n e" << '\n';
	cout << "- -----------" << '\n';
	for (int i = 0; i < 10; i++) {
		if (i > 2) {
			cout << fixed;
			cout.precision(9);
		}
		cout << i << ' ' << e(i) << '\n';
	}
}