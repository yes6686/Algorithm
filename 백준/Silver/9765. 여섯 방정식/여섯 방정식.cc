//2
#include <iostream>
using namespace std;

pair<int, int>arr1[2];
pair<int, int>arr2[2];

long long int gcd(long long int x, long long int y) {
	if (y == 0) {
		return x;
	}
	else {
		return gcd(y, x % y);
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long long int c1, c2, c3, c4, c5, c6;
	cin >> c1 >> c2 >> c3 >> c4 >> c5 >> c6;
	long long int x1, x2, x3, x4, x5, x6, x7,x8;
	
	x2 = gcd(c1, c5);
	x1 = c1 / x2;
	x6 = gcd(c3, c6);
	x7 = c3 / x6;
	x3 = c5 / x2;
	x4 = c4 * x1;
	x5 = c6 / x6;
	
	cout << x1 << " " << x2 << " " << x3 << " " << x5 << " " << x6 << " " << x7 << '\n';
}