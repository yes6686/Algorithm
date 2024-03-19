#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		if (s.size() <= 9 && s.size() >= 6) {
			cout << "yes" << '\n';
		}
		else {
			cout << "no" << '\n';
		}
	}
}