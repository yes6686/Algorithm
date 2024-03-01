#include <iostream>
using namespace std;
int main() {
	int m, d;
	cin >> m >> d;
	if (m == 2 && d == 18) {
		cout << "Special" << '\n';
	}
	else if (m > 2 || (m == 2 && d > 18)) {
		cout << "After" << '\n';
	}
	else {
		cout << "Before" << '\n';
	}
}