#include <iostream>
using namespace std;

int gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;
}

int main() {
	int n, m;
	cin >> n >> m;
	int k = gcd(n, m);
	cout << k * (m/k - 1);
}