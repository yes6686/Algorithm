#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	while (T--) {
		string s1, s2;
		cin >> s1 >> s2;
		int cnt0 = 0, cnt1 = 0;
		for (int i = 0; i < s1.size(); i++) {
			if (s1[i] != s2[i]) {
				if (s1[i] == '0') {
					cnt0++;
				}
				else {
					cnt1++;
				}
			}
		}
		if (cnt0 < cnt1) {
			cout << cnt0 + (cnt1 - cnt0)<<'\n';
		}
		else {
			cout << cnt1 + (cnt0 - cnt1)<<'\n';

		}
	}
}