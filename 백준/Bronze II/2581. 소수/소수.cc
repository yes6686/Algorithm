#include <iostream>
using namespace std;

int main() {
	
	int n, m;
	cin >> n >> m;
	int cnt = 0;
	int sum = 0;
	int min = 10001;
	for (int i = n; i <= m; i++) {
		for (int j = 1; j <= i; j++) {
			if (i % j == 0) {
				cnt++;
			}
		}
		if (cnt == 2) {
			sum += i;
			if (min > i) {
				min = i;
			}
		}
		cnt = 0;
	}
	if (sum == 0) cout << -1;
	else {
		cout << sum << '\n' << min;
	}
}