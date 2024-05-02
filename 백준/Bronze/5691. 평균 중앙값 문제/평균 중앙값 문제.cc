#include <iostream>
using namespace std;
int main() {
	while (1) {
		int a, b;
		cin >> a >> b;
		if (a == 0 && b == 0) break;
		cout << 2 * a - b << '\n';
	}
}