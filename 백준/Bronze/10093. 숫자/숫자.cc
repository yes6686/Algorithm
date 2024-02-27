#include <iostream>
#include <algorithm>
using namespace std;

int arr[11];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int a, b;
	cin >> a >> b;

	if (a > b) {
		int temp = a;
		a = b;
		b = temp;
	}
	if (b - a <= 1) {
		cout << 0;
		return 0;
	}
	cout << b - a - 1 << '\n';
	for (int i = a + 1; i < b; i++) {
		cout << i << ' ';
	}
}