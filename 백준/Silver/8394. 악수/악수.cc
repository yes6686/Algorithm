#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	if (n == 1 || n == 2 || n == 3) {
		cout << n << '\n';
		return 0;
	}
	else {
		int a = 1;
		int b = 2;
		int c = 3;
		for (int i = 3; i <= n; i++) {
			c = (a + b) % 10;
			a = b;
			b = c;
		}
		cout << c << '\n';
	}	
}