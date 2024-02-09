#include <iostream>
using namespace std;

int main() {
	int n;
	int x;
	int cnt = 0;
	cin >> n;
	for (int i = 0; i < 5; i++) {
		cin >> x;
		if (n == x) {
			cnt++;
		}

	}
	cout << cnt;
}