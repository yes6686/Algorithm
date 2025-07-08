#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string s;
	cin >> s;

	int ans = 0;
	for (int i = 0;i < s.size();i++) {
		if (s[i] == 'Y') {
			ans++;
			for (int j = i;j < s.size();j += (i + 1)) {
				s[j] = (s[j] == 'Y') ? 'N' : 'Y';
			}
		}
	}
	cout << ans << '\n';
}