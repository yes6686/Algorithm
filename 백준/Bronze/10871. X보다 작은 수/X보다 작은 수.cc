#include <iostream>
using namespace std;

int main() {
	int n, x;
	cin >> n >> x;
	int k;
	for (int i = 0; i < n; i++) {
		cin >> k;
		if (k < x) {
			cout << k << ' ';
		}
	}
}