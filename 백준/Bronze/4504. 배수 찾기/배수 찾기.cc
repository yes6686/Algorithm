#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	while (1) {
		int x;
		cin >> x;
		if (x == 0) break;
		if (x % n == 0) {
			cout << x << " is a multiple of " << n << "." << '\n';
		}
		else {
			cout << x << " is NOT a multiple of " << n << "." << '\n';
		}
	}
}