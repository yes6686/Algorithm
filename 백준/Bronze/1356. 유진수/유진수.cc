#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string s;
	cin >> s;

	int k = 1;
	int zeroCnt = 0;

	for (int i = 0;i < s.size();i++) {
		if (s[i] == '0') zeroCnt++;
		k *= (s[i] - '0');
	}

	if (zeroCnt == 1) {
		cout << "NO" << '\n';
	}
	else if (zeroCnt >= 2) {
		cout << "YES" << '\n';
	}
	else {

		int v = 1;

		for (int i = 0;i < s.size()-1;i++) {
			v *= (s[i] - '0');
			k /= (s[i] - '0');
			if (v == k) {
				cout << "YES" << '\n';
				return 0;
			}
		}
		cout << "NO" << '\n';
	}
}