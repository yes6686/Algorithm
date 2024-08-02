#include <iostream>
using namespace std;

int main() {
	int n, a, d;
	cin >> n >> a >> d;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (x == a) {
			cnt++;
			a += d;
		}
	}
	cout << cnt;
}