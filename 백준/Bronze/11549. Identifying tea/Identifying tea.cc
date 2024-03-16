#include <iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	int x;
	int cnt = 0;
	for (int i = 0; i < 5; i++) {
		cin >> x;
		if (x == n) {
			cnt++;
		}
	}
	cout << cnt;
}