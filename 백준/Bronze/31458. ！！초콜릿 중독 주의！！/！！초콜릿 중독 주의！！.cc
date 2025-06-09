#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	while (T--) {
		string s;
		cin >> s;

		for (int i = 0;i < s.size();i++) {
			if (s[i] != '!') {
				int ans = s[i]-'0';
				int lCnt = i;
				int rCnt = s.size() - i - 1;
				if (rCnt > 0) {
					ans = 1;
				}
				if (lCnt % 2 == 0) {
					cout << ans << '\n';
				}
				else {
					ans  = (ans == 1) ? 0 : 1;
					cout << ans << '\n';
				}
			}
		}
	}
}