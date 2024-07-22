#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	long long int d;
	cin >> d;
	long long int n, m, k;
	cin >> n >> m >> k;
	long long int maxMandoCnt = (n + m + k)/d;
	while (true) {
		if ((n / d + m / d + k / d) == maxMandoCnt) break;
		if (n % d > m % d) {
			k -= (d - (n % d));
			n += (d - (n % d));
		}
		else {
			k -= (d - (m % d));
			m += (d - (m % d));
		}
	}
	cout << k;
}