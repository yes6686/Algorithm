#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	while (T--) {
		long long int n;
		cin >> n;
		if (n <=1) {
			cout << 2 << '\n';
			continue;
		}
		while (true) {
			int check = 1;
			for (long long int i = 2; i * i <= n; i++) {
				if (n % i == 0) {
					check = 0;
					break;
				}
			}
			if (check == 1) {
				cout << n << '\n';
				break;
			}
			else {
				n++;
			}
		}
	}
}