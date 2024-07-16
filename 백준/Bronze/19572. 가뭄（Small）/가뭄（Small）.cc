#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	double d1, d2, d3;
	cin >> d1 >> d2 >> d3;
	double a, b, c;
	b = (d1 - d2 + d3) / 2;
	a = d1 - b;
	c = d2 - a;
	cout << fixed;
	cout.precision(1);
	if (a > 0 && b > 0 && c > 0) {
		cout << 1 << '\n';
		cout << a << ' ' << b << ' ' << c;
	}
	else
		cout << -1;
}