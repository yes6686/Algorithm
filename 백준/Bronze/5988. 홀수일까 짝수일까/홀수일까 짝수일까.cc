#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		int k = s.back() - '0';
		if (k % 2 == 0) {
			cout << "even" << '\n';
		}
		else {
			cout << "odd" << '\n';
		}
	}
}