#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int x;
	cin >> x;

	int cnt = 0;
	for (int i = 1;i <= x;i++) {
		for (int j = 1;j <= i;j++) {
			cnt++;
			if (cnt == x) {
				if (i % 2 == 0) {
					cout << j << "/" << i - j + 1 << '\n';
				}
				else {
					cout << i - j + 1 << "/" << j << '\n';
				}
				return 0;
			}
		}
	}
}