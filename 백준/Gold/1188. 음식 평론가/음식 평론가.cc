#include <iostream>
using namespace std;

int gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;
}

int main() {
	int n, m;
	cin >> n >> m;
	int k = gcd(n, m);
	if (n % m == 0) {
		cout << 0 ;
	}
	else {
		n /= k;
		m /= k;
		cout << k*(m - 1);
	}
}