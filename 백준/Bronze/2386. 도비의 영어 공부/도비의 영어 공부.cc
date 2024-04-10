#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	while (1) {
		char c;
		cin >> c;
		if (c == '#') break;
		string s;
		getline(cin, s);
		int cnt = 0;
		for (int i = 0; i < s.size(); i++) {
			if (c == s[i] || c==s[i]+32) cnt++;
		}
		cout << c << ' ' << cnt << '\n';
	}
}