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
		int ans = 0;
		int k = 1;
		for (int i = s.size() - 1; i >= 0; i--) {
			if (s[i] == '1') {
				ans += k;
			}
			k *= 2;
		}
		cout << ans << '\n';
	}
}