#include <iostream>
using namespace std;
int main() {
	int n; cin >> n;
	int k = 1;
	for (int i = n-3; i <= n; i++) {
		k *= i;
	}
	cout << k / 24;
}