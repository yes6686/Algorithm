#include <iostream>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	long long int a, b;
	cin >> a >> b;

	if (a > b) {
		long long int temp = a;
		a = b;
		b = temp;
	}
	if (b - a <= 1) {
		cout << 0;
		return 0;
	}
	cout << b - a - 1 << '\n';
	for (long long int i = a + 1; i < b; i++) {
		cout << i << ' ';
	}
}