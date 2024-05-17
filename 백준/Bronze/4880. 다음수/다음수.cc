#include <iostream>
using namespace std;

int main() {
	while (1) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 0 && b == 0 && c == 0) break;

		if (b - a == c - b) {
			cout << "AP" << ' '<<c + c - b<<'\n';
		}
		else {
			cout << "GP" << ' ' << c * (c / b)<<'\n';
		}
	}
}