#include<iostream>
#include <string.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;

		for (int i = 2; i * i <= n; i++) {
			int cnt = 0;
			while (n % i == 0) {
				n /= i;
				cnt++;
			}
			if (cnt) {
				cout << i << ' ' << cnt << '\n';
			}
		}
		if (n > 1) {
			cout << n << ' ' << 1 << '\n';
		}
	}
}