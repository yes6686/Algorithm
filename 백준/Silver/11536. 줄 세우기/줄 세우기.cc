#include <iostream>
using namespace std;

string s[21];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}
	int increasingCheck = 1;
	int decreasingCheck = 1;
	for (int i = 1; i < n; i++) {
		if (s[i] > s[i - 1]) {
			decreasingCheck = 0;
		}
		else {
			increasingCheck = 0;
		}
	}
	if (increasingCheck == 1) {
		cout << "INCREASING";
	}
	else if (decreasingCheck == 1) {
		cout << "DECREASING";
	}
	else {
		cout << "NEITHER";
	}
}