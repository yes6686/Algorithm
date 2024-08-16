#include <iostream>
#include <cmath>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	while (T--) {
		long long int n;
		cin >> n;
		int cnt = 0;
		long long int k = 5;
		while (true) {
			if (k > n) break;
			cnt += (n / k);
			k *= 5;

		}
		cout << cnt << '\n';
	}
}