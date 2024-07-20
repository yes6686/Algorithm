#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long long int x;
	cin >> x;
	if (x == 0) {
		cout << "NO";
		return 0;
	}
	while (true) {
		if (x == 0) break;
		if (x % 3 == 2) {
			cout << "NO";
			return 0;
		}
		x /= 3;
	}
	cout << "YES";
}