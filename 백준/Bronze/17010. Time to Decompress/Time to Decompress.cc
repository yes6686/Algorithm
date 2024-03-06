#include <iostream>
using namespace std;
int main() {
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		char c;
		cin >> c;
		for (int i = 0; i < n; i++) {
			cout << c;
		}
		cout << '\n';
	}
}