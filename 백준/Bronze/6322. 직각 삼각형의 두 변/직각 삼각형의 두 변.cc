#include <iostream>
#include <cmath>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t = 1;
	while (true) {
		double a, b, c;
		cin >> a >> b >> c;
		if (a == 0 && b == 0 && c == 0) {
			break;
		}
		cout << "Triangle #" << t++ << '\n';
		cout << fixed;
		cout.precision(3);
		if (a == -1) {	
			a = sqrt(c * c - b * b);
			if (a + b > c) {
				cout << "a = " << a << '\n';
			}
			else {
				cout << "Impossible." << '\n';
			}
		}
		else if (b == -1) {
			b = sqrt(c * c - a * a);
			if (a + b > c) {
				cout << "b = " << b << '\n';
			}
			else {
				cout << "Impossible." << '\n';
			}
		}
		else {
			c = sqrt(a * a + b * b);
			if (a + b > c) {
				cout << "c = " << c << '\n';
			}
			else {
				cout << "Impossible." << '\n';
			}
		}
		cout << '\n';
	}
}