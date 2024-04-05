#include <iostream>
using namespace std;
int main() {
	int a, b, n;
	cin >> a >> b >> n;
	while (n--) {
		a %= b;
		a *= 10;
	}
	cout << a/b;
}