#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	for (int i = 0;i < n;i++) {
		string s;
		cin >> s;
		if (s[s.size() / 2 - 1] == s[s.size() / 2]) {
			cout << "Do-it" << '\n';
		}
		else {
			cout << "Do-it-Not" << '\n';
		}
	}
}