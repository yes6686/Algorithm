#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	while (true) {
		string s;
		cin >> s;

		if (s == "#") break;

		int oneCnt = 0;

		for (int i = 0;i < s.size() - 1;i++) {
			cout << s[i];
			if (s[i] == '1') oneCnt++;
		}

		if (s[s.size() - 1] == 'e') {
			if (oneCnt % 2 == 0) {
				cout << 0 << '\n';
			}
			else {
				cout << 1 << '\n';
			}
		}
		else {
			if (oneCnt % 2 == 0) {
				cout << 1 << '\n';
			}
			else {
				cout << 0 << '\n';
			}
		}
	}
}