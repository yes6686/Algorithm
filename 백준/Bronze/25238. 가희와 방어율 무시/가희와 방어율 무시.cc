#include <iostream>
using namespace std;

int main() {
	double a, b;
	cin >> a >> b;
	double k = (a/100)* b;
	a -= k;
	if (a < 100) {
		cout << 1;
	}
	else {
		cout << 0;
	}
}