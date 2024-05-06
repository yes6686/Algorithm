#include <iostream>
using namespace std;

int p[1000001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	for (int i = 2; i <= 1000000; i++) {
		p[i] = i;
	}
	// 에라토스테네스의 체
	for (int i = 2; i * i <= 1000000; i++) {
		if (p[i] == 0) continue;
		for (int j = i * i; j <= 1000000; j += i) {
			p[j] = 0;
		}
	}

	int T;
	cin >> T;
	while (T--) {
		int x;
		cin >> x;
		int cnt = 0;
		for (int i = 2; i <= x/2; i++) {
			if (p[i] && p[x - i] ) {
				cnt++;
			}
		}
		cout << cnt << '\n';
	}
}