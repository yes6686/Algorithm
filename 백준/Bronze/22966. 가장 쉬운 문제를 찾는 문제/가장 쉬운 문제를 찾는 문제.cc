#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int minLevel = 5;
	string ans;
	for (int i = 0; i < n; i++) {
		string s;
		int x;
		cin >> s >> x;
		if (minLevel > x) {
			minLevel = x;
			ans = s;
		}
	}
	cout << ans;
}