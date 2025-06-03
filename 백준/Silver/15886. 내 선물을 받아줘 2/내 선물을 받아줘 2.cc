#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);


	int n;
	cin >> n;
	string s;
	cin >> s;

	int ans = 1;
	for (int i = 0;i < n-1;i++) {
		if (s[i] == 'W' && s[i + 1] == 'E') {
			ans++;
		}
	}
	cout << ans << '\n';
}